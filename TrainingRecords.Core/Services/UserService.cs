using TrainingRecords.Core.Interfaces;
using TrainingRecords.Core.Services.Interfaces;

namespace TrainingRecords.Core.Services;

public class UserService : IUserService
{
    private readonly IUserRepository _repository;

    public UserService(IUserRepository repository)
    {
        _repository = repository;
    }

    public async Task<bool> CheckCredentials(string username, string password) { 

        return await _repository.CheckCredentials(username, password); 
    }

    public bool CheckCredentials(int v, string custom)
    {
        throw new NotImplementedException();
    }
}
