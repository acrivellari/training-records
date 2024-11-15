using Microsoft.Extensions.Options;
using Microsoft.IdentityModel.Tokens;
using Newtonsoft.Json;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Text;
using TrainingRecords.Core.Constants;
using TrainingRecords.Core.Interfaces;
using TrainingRecords.Core.Services.Interfaces;
using TrainingRecords.Core.Shared.Interfaces;
using TrainingRecords.Core.Shared.Models.Generic;

namespace TrainingRecords.WebApi.Services;

public class JwtTokenService : IJwtTokenService
{
    private readonly JwtTokenConfig _jwtTokenConfig;
    private readonly ICurrentUserService _currentUserService;
    private readonly IUserRepository _repository;

    public JwtTokenService(IOptions<JwtTokenConfig> jwtTokenConfig, ICurrentUserService currentUserService, IUserRepository repository)
    {
        _jwtTokenConfig = jwtTokenConfig.Value;
        _currentUserService = currentUserService;
        _repository = repository;
    }

    public (string, DateTime) GenerateAccessToken(
        int claimIdentifier,
        string claimName,
        string custom_check_field,
        IEnumerable<string> roles)
    {
        var tokenExpiringDate = DateTime.Now.AddMinutes(_jwtTokenConfig.AccessTokenExpiration);
        var claims = new List<Claim>
        {
            new(ClaimTypes.NameIdentifier, claimIdentifier.ToString()),
            new(ClaimTypes.Name, claimName),
            new(ClaimNames.CustomCheck, custom_check_field),
            new(ClaimTypes.Role, JsonConvert.SerializeObject(roles), JsonClaimValueTypes.JsonArray)
        };


        var key = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(_jwtTokenConfig.Secret));
        var credentials = new SigningCredentials(key, SecurityAlgorithms.HmacSha512Signature);

        var tokenDescriptor = new SecurityTokenDescriptor
        {
            Subject = new(claims),
            Issuer = _jwtTokenConfig.Issuer,
            Audience = _jwtTokenConfig.Audience,
            Expires = tokenExpiringDate,
            SigningCredentials = credentials
        };

        var tokenHandler = new JwtSecurityTokenHandler();
        var token = tokenHandler.CreateToken(tokenDescriptor);

        return (tokenHandler.WriteToken(token), tokenExpiringDate);
    }

    public string GetTokenOwner(string token) => _currentUserService.UserName;

    public (int?, string) GetTokenCredentials(string token) => (_currentUserService.UserId, _currentUserService.Password);

    public string GenerateRefreshToken(int claimIdentifier)
    {
        var tokenExpirationDate = DateTime.UtcNow.AddMinutes(_jwtTokenConfig.RefreshTokenExpiration);
        var claims = new List<Claim>
        {
            new(ClaimTypes.NameIdentifier, claimIdentifier.ToString()),
            new(ClaimTypes.Expiration, tokenExpirationDate.ToString()),
            new(ClaimNames.IPAddress, _currentUserService.IPv4Address),
        };

        var key = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(_jwtTokenConfig.RefreshTokenSecret));
        var credentials = new SigningCredentials(key, SecurityAlgorithms.HmacSha512Signature);

        var tokenDescriptor = new SecurityTokenDescriptor
        {
            Subject = new(claims),
            Issuer = _jwtTokenConfig.Issuer,
            Audience = _jwtTokenConfig.Audience,
            Expires = tokenExpirationDate,
            SigningCredentials = credentials
        };

        var tokenHandler = new JwtSecurityTokenHandler();
        var token = tokenHandler.CreateToken(tokenDescriptor);

        return tokenHandler.WriteToken(token);
    }


    public int? ValidateRefreshToken(string refreshToken)
    {
        var validationParameters = new TokenValidationParameters
        {
            ValidateIssuerSigningKey = true,
            ValidateIssuer = true,
            ValidateAudience = true,
            ValidateLifetime = true,
            IssuerSigningKey = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(_jwtTokenConfig.RefreshTokenSecret)),
            ValidIssuer = _jwtTokenConfig.Issuer,
            ValidAudience = _jwtTokenConfig.Audience,
            ClockSkew = TimeSpan.Zero
        };

        var jwtSecurityTokenHandler = new JwtSecurityTokenHandler();

        try
        {
            var claimsPrincipal = jwtSecurityTokenHandler.ValidateToken(
                refreshToken,
                validationParameters,
                out var validatedToken);

            var isValidUserId = int.TryParse(
                claimsPrincipal.Claims?.SingleOrDefault(c => c.Type == ClaimTypes.NameIdentifier).Value,
                out var tokenUserId);

            var ipAddress = claimsPrincipal.Claims?.SingleOrDefault(c => c.Type == ClaimNames.IPAddress).Value;
            var expiration = claimsPrincipal.Claims?.SingleOrDefault(c => c.Type == ClaimTypes.Expiration).Value;

            var isValid = isValidUserId
                && ipAddress == _currentUserService.IPv4Address
                && DateTime.TryParse(expiration, out var expirationDateTime)
                && DateTime.UtcNow <= expirationDateTime;

            return isValid
                ? tokenUserId
                : null;
        }
        catch (Exception)
        {
            return null;
        }
    }
}