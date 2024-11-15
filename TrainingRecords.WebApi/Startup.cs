using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.Extensions.FileProviders;
using Microsoft.Extensions.Options;
using Microsoft.IdentityModel.Tokens;
using System.Text;
using System.Text.Json.Serialization;
using TrainingRecords.Core.DataAccess.Context;
using TrainingRecords.Core.DataAccess.Repositories;
using TrainingRecords.Core.Interfaces;
using TrainingRecords.Core.Services;
using TrainingRecords.Core.Services.Interfaces;
using TrainingRecords.Core.Shared.Interfaces;
using TrainingRecords.Core.Shared.Models.Config;
using TrainingRecords.Core.Shared.Models.Generic;
using TrainingRecords.WebApi.Extensions;
using TrainingRecords.WebApi.Handlers;
using TrainingRecords.WebApi.Hubs;
using TrainingRecords.WebApi.Services;
using TrainingRecords.WebApi.Services.Interfaces;

namespace TrainingRecords.WebApi;

public class Startup
{
    public Startup(IConfiguration configuration)
    {
        Configuration = configuration;
    }

    public IConfiguration Configuration { get; }

    public void ConfigureServices(IServiceCollection services)
    {
        // IIS configuration
        services.Configure<IISOptions>(options => { options.AutomaticAuthentication = false; });

        // Automapper for DTOs
        services.AddAutoMapper(AppDomain.CurrentDomain.GetAssemblies());

        // Dependency injection for entities repository
        SetupRepositories(services);

        services.ConfigureFluentMigrator(Configuration);

        // Dependency injection for entities service layer
        SetupServiceLayer(services);

        // JWT configuration
        SetupAuthentication(services);

        // Swagger
        //SetupApiDocumentation(services);

        // Global cors policy
        services.AddCors();

        services.AddMemoryCache();

        services.AddSignalR();

        services.AddControllers();

        services.AddControllers()
            .AddJsonOptions(options => options.JsonSerializerOptions.Converters.Add(new JsonStringEnumConverter()));
    }

    private void SetupAuthentication(IServiceCollection services)
    {
        var jwtTokenConfig = Configuration.GetSection("JWTTokenConfig").Get<JwtTokenConfig>();

        services.AddOptions<JwtTokenConfig>().BindConfiguration("JWTTokenConfig");
        services.AddScoped<IJwtTokenService, JwtTokenService>();

        services.AddAuthentication(x =>
        {
            x.DefaultAuthenticateScheme = JwtBearerDefaults.AuthenticationScheme;
            x.DefaultChallengeScheme = JwtBearerDefaults.AuthenticationScheme;
        }).AddJwtBearer(x =>
        {
            x.RequireHttpsMetadata = true;
            x.SaveToken = true;
            x.TokenValidationParameters = new TokenValidationParameters
            {
                ValidateIssuer = true,
                ValidIssuer = jwtTokenConfig.Issuer,
                ValidateIssuerSigningKey = true,
                IssuerSigningKey = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(jwtTokenConfig.Secret)),
                ValidAudience = jwtTokenConfig.Audience,
                ValidateAudience = true,
                ValidateLifetime = true,
                // set clockskew to zero so tokens expire exactly at token expiration time (instead of 5 minutes later)
                ClockSkew = TimeSpan.FromSeconds(0)
            };
            x.SecurityTokenValidators.Clear();
            // Add custom token validation
            x.SecurityTokenValidators.Add(new CustomJwtValidatorHandler(services.BuildServiceProvider()));
            // Add authentication for SignalR
            x.Events = new JwtBearerEvents
            {
                OnMessageReceived = context =>
                {
                    var accessToken = context.Request.Query["access_token"];

                    // If the request is for the hub
                    var path = context.HttpContext.Request.Path;
                    if (!string.IsNullOrEmpty(accessToken) &&
                        (path.StartsWithSegments("/api/chathub")))
                    {
                        // Read the token out of the query string
                        context.Token = accessToken;
                    }

                    return Task.CompletedTask;
                }
            };
        });
    }

    private void SetupServiceLayer(IServiceCollection services)
    {
        // Configuring the service to get the Base URL
        services.AddHttpContextAccessor();
        services.AddScoped<IUriService>(o =>
        {
            var accessor = o.GetRequiredService<IHttpContextAccessor>();
            var request = accessor.HttpContext.Request;
            var uri = string.Concat(request.Scheme, "://", request.Host.ToUriComponent());
            return new UriService(uri, request);
        });
        services.AddHttpClient();

        services.AddOptions<GoogleMapsConfig>().BindConfiguration("GoogleMapsConfig");

        // Configuring other services
        services.AddScoped<IUserService, UserService>();
        services.AddScoped<ICurrentUserService, CurrentUserService>();
    }

    private void SetupRepositories(IServiceCollection services)
    {
        services.AddScoped<DbContext>();
        services.AddScoped<IUserRepository, UserRepository>();
    }

    public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
    {
        if (env.IsDevelopment())
        {
            app.UseDeveloperExceptionPage();
        }

        app.UseHttpsRedirection();

        // Swagger
        //ConfigureApiDocumentation(app);

        app.UseRouting();

        ConfigureCors(app);

        // JWT middleware
        app.UseAuthentication();
        app.UseAuthorization();

        app.UseMiddleware<GlobalExceptionHandler>();

        app.UseEndpoints(endpoints =>
        {
            endpoints.MapControllers();
            endpoints.MapHub<ChatHub>("/api/chathub");
        });
    }

    private void ConfigureCors(IApplicationBuilder app)
    {
        // Global cors policy
        // SetIsOriginAllowed(_ => true) is used to apply credencials with all origins
        // WithOrigins("http://localhost:8080")
        // WithOrigins("null")
        app.UseCors(builder => builder
            .AllowAnyHeader()
            .AllowAnyMethod()
            .SetIsOriginAllowed(_ => true)
            .AllowCredentials()
        );
    }
}