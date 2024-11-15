using Microsoft.Extensions.Configuration;
using Npgsql;
using System.Data;
using System.Data.SqlClient;

namespace TrainingRecords.Core.DataAccess.Context;
public class DbContext
{
    private readonly string _connectionString;

    public DbContext(IConfiguration configuration)
    {
        _connectionString = configuration.GetConnectionString("Db");
    }

    public IDbConnection CreateConnection() => new NpgsqlConnection(_connectionString);
}