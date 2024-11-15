using FluentMigrator.Runner;
using TrainingRecords.Core.DataAccess.Context;

namespace TrainingRecords.WebApi.Extensions;

public static class ServiceCollectionExtension
{
    internal static void ConfigureFluentMigrator(this IServiceCollection services, IConfiguration configuration)
    {
        services.AddFluentMigratorCore()
            .ConfigureRunner(builder => builder
                .AddSqlServer()
                .WithGlobalConnectionString(configuration.GetConnectionString("AtworkDb"))
                .ScanIn(typeof(DbContext).Assembly).For.Migrations())
            .AddLogging(builder => builder.AddFluentMigratorConsole());

        // services.MigrateDatabase();
    }
}
