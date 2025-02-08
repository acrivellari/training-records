using Azure;
using Microsoft.AspNetCore.Http;
using TrainingRecords.Core.Models;
using TrainingRecords.Core.Shared.Models.Filters;


namespace TrainingRecords.Core.Services.Interfaces;


public interface IUserService
{
    bool CheckCredentials(int userId, string pwd);
    Task<Users?> CheckCredentials(string username, string password);
    Task<string?> GetUsernameById(int? userId);
}