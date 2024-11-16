using System.Data.Common;
using System.Data.SqlClient;
using Dapper;
using Microsoft.Extensions.Configuration;
using Microsoft.Identity.Client;
using TrainingRecords.Core.DataAccess.Context;
using TrainingRecords.Core.Interfaces;

namespace TrainingRecords.Core.DataAccess.Repositories;

public class UserRepository : IUserRepository
{
    private readonly IConfiguration _configuration;
    private readonly DbContext _dbContext;

    private const int EnglishLanguageId = 122;


    public UserRepository(IConfiguration configuration, DbContext dbContext)
    {
        _configuration = configuration;
        _dbContext = dbContext;
    }

    public void Dispose() { }

    public void AddEntity(int entity)
    {
        throw new NotImplementedException();
    }

    public void UpdateEntity(int entity)
    {
        throw new NotImplementedException();
    }

    public void DeleteEntity(int entity)
    {
        throw new NotImplementedException();
    }

    public async Task<bool> CheckCredentials(string username, string password)
    {

        DbConnection conn = GetDbconnection();
        conn.Open();
        var cmd =conn.CreateCommand();
        cmd.CommandText = "select username, password from dev.users where username='"+username+"' AND password='"+password+"'";
        var reader = await cmd.ExecuteReaderAsync();
        return reader.HasRows;
    }

    public DbConnection GetDbconnection()
    {
        return (DbConnection)_dbContext.CreateConnection();
    }
}
