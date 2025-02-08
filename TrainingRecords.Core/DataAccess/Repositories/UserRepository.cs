using System.Data;
using System.Data.Common;
using System.Data.SqlClient;
using Dapper;
using Dapper.Contrib.Extensions;
using Microsoft.Extensions.Configuration;
using Microsoft.Identity.Client;
using TrainingRecords.Core.DataAccess.Context;
using TrainingRecords.Core.Interfaces;
using TrainingRecords.Core.Models;
using static Dapper.SqlMapper;

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

    public async Task<Users?> GetByUsername(string username)
    {
        {
            var parameters = new DynamicParameters();

            var sql = @"SELECT *
                FROM dev.users
                WHERE username = @p1 ";

            parameters.Add("@p1", username);

            using IDbConnection db = GetDbconnection();

            var data = await db.QueryAsync
            (
                sql,
                new[]
                {
                typeof(Users)
                },
                objects =>
                {
                    return objects[0] as Users;
                },
                parameters,
                splitOn: "Id"
            );

            return data.Any()
                ? data.FirstOrDefault()
                : null;
        }
    }

    public async Task<string?> GetUsernameById(int userId)
    {
        var parameters = new { userId };
        var sql = $@"SELECT * FROM dev.users WHERE Id = @userId";
        using var db = GetDbconnection();
        return (await db.QueryFirstAsync<Users>(sql, parameters))?.Username;
    }

    public void AddEntity(Users entity)
    {
        throw new NotImplementedException();
    }

    public void UpdateEntity(Users entity)
    {
        throw new NotImplementedException();
    }

    public void DeleteEntity(Users entity)
    {
        throw new NotImplementedException();
    }


}
