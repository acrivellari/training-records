using Azure;
using Microsoft.AspNetCore.Http;
using TrainingRecords.Core.Shared.Models.Filters;


namespace TrainingRecords.Core.Services.Interfaces;


public interface IUserService
{
    bool CheckCredentials(int v, string custom);
    Task<bool> CheckCredentials(string username, string password);
}