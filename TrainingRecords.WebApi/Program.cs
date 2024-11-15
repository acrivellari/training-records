namespace TrainingRecords.WebApi;

public class Program
{
    public static void Main(string[] args)
    {
        Host.CreateDefaultBuilder(args)
            .ConfigureWebHostDefaults(builder => 
            {
                builder.UseIISIntegration();
                builder.UseStartup<Startup>();
            })
            .Build()
            .Run();

    }
}
