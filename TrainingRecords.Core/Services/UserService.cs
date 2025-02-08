using TrainingRecords.Core.Interfaces;
using TrainingRecords.Core.Models;
using TrainingRecords.Core.Services.Interfaces;

namespace TrainingRecords.Core.Services;

public class UserService : IUserService
{
    private readonly IUserRepository _repository;

    public UserService(IUserRepository repository)
    {
        _repository = repository;
    }

    public async Task<Users?> CheckCredentials(string? username, string password) {
        return await _repository.GetByUsername(username);
    }

    public bool CheckCredentials(int userId, string pwd)
    {
        var taskUsername = _repository.GetUsernameById(userId);
        taskUsername.Wait();
        var taskcheck = CheckCredentials(taskUsername.Result, pwd);
        taskcheck.Wait();
        return taskcheck.Result is not null;
    }

    public async Task<string?> GetUsernameById(int? userId)
    {
        return (userId is not null) 
            ? await _repository.GetUsernameById((int)userId)
            : null;
    }
}
