using Microsoft.AspNetCore.Http;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Claims;
using System.Text;
using System.Threading.Tasks;
using TrainingRecords.Core.Constants;
using TrainingRecords.Core.Services.Interfaces;

namespace TrainingRecords.Core.Services;

public class CurrentUserService : ICurrentUserService
{
    private readonly IHttpContextAccessor _httpContextAccessor;

    public CurrentUserService(IHttpContextAccessor httpContextAccessor) => _httpContextAccessor = httpContextAccessor;

    public int UserId => int.TryParse(
        UserClaims?.SingleOrDefault(c => c.Type == ClaimTypes.NameIdentifier)?.Value,
        out var userId)
            ? userId
            : 0;

    public string UserName => UserClaims?.SingleOrDefault(c => c.Type == ClaimTypes.Name)?.Value ?? string.Empty;

    public string Password => UserClaims?.SingleOrDefault(c => c.Type == ClaimNames.CustomCheck)?.Value ?? string.Empty;

    public IReadOnlyCollection<string> Roles => (UserClaims
        ?.Where(c => c.Type == ClaimTypes.Role)
        ?.Select(c => c.Value)
        ?? Enumerable.Empty<string>()).ToArray();

    public string IPv4Address => _httpContextAccessor.HttpContext.Connection.RemoteIpAddress.MapToIPv4().ToString() ?? string.Empty;

    private IEnumerable<Claim> UserClaims => _httpContextAccessor.HttpContext?.User.Claims;
}
