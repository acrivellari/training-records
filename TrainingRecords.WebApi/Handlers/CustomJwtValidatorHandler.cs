using Microsoft.IdentityModel.Tokens;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using TrainingRecords.Core.Services.Interfaces;

namespace TrainingRecords.WebApi.Handlers;
public class CustomJwtValidatorHandler : JwtSecurityTokenHandler
{
    private readonly IUserService _userService;

    public CustomJwtValidatorHandler(IServiceProvider serviceProvider)
    {
        this._userService = serviceProvider.GetRequiredService<IUserService>();
    }

    public override ClaimsPrincipal ValidateToken
    (
        string securityToken,
        TokenValidationParameters validationParameters,
        out SecurityToken validatedToken
    )
    {
        JwtSecurityToken jwtToken = (JwtSecurityToken)ReadToken(securityToken);

        if (jwtToken == null)
        {
            throw new SecurityTokenValidationException();
        }

        string custom_check_field = jwtToken.Claims.ToList().Where(x => x.Type.Equals("custom_check")).FirstOrDefault().Value;
        string claimIdentifier = jwtToken.Claims.ToList().Where(x => x.Type.Equals("nameid")).FirstOrDefault().Value;

        if (!"".Equals(custom_check_field) &&
            !"".Equals(claimIdentifier) &&
            custom_check_field != null &&
            claimIdentifier != null &&
            _userService.CheckCredentials(Int32.Parse(claimIdentifier), custom_check_field))
        {
            return base.ValidateToken
            (
                securityToken,
                validationParameters,
                out validatedToken
            );
        }
        else
        {
            throw new SecurityTokenValidationException();
        }
    }
}