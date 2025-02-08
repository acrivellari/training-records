using System.Data.Common;
using TrainingRecords.Core.Models;
using TrainingRecords.Core.Shared;

namespace TrainingRecords.Core.Interfaces;

public interface IUserRepository : IRepositoryBase<Users>
{
    public void AddEntity(int entity)
    {
        throw new NotImplementedException();
    }

    public void DeleteEntity(int entity)
    {
        throw new NotImplementedException();
    }

    public void Dispose()
    {
        throw new NotImplementedException();
    }

    public void UpdateEntity(int entity)
    {
        throw new NotImplementedException();
    }

    public Task<Users?> GetByUsername(string? username);
    Task<string?> GetUsernameById(int userId);
}
