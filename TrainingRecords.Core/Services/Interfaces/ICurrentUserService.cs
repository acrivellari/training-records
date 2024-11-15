namespace TrainingRecords.Core.Services.Interfaces;
public interface ICurrentUserService
{
    public int UserId { get; }

    public string UserName { get; }

    public string Password { get; }

    public IReadOnlyCollection<string> Roles { get; }

    public string IPv4Address { get; }
}
