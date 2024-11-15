using Azure;
using Microsoft.AspNetCore.Http;
using TrainingRecords.Core.Shared.Models.Filters;


namespace TrainingRecords.Core.Services.Interfaces;


public interface IUserService
{

    bool CheckCredentials(int v, string custom_check_field);
}