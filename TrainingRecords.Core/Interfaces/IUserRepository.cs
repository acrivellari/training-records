using System.Data.Common;
using TrainingRecords.Core.Shared;

namespace TrainingRecords.Core.Interfaces;

public interface IUserRepository : IRepositoryBase<int>
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

    public Task<string> Prova();
}
