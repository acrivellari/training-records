namespace TrainingRecords.Core.Shared.Interfaces;


public interface IJwtTokenService
{
    /// <summary>
    /// Creates the token and returns it with the expiration date
    /// </summary>
    /// <param name="claimIdentifier">User's ID connected to the token</param>
    /// <param name="claimName">User's name connected to the token</param>
    /// <param name="custom_check_field">Custom filed to use in token validation</param>
    /// <param name="roles">Set of roles for user</param>
    /// <returns>
    /// The token string and its expiration date
    /// </returns>
    (string, DateTime) GenerateAccessToken(int claimIdentifier, string claimName, string custom_check_field, IEnumerable<string> roles);

    /// <summary>
    /// Gets the user's name connected to the token
    /// </summary>
    /// <param name="token">Token string</param>
    /// <returns>
    /// The token owner's full name
    /// </returns>
    string GetTokenOwner(string token);

    /// <summary>
    /// Gets the credentials connected to the token
    /// </summary>
    /// <param name="token">Token string</param>
    /// <returns>
    /// The token owner's credentials
    /// </returns>
    (int?, string) GetTokenCredentials(string token);

    string GenerateRefreshToken(int claimIdentifier);

    int? ValidateRefreshToken(string refreshToken);
}
