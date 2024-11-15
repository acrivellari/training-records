using Newtonsoft.Json;
using System.Data.SqlClient;
using System.Net;
using TrainingRecords.WebApi.Models.Common;

namespace TrainingRecords.WebApi.Handlers;

public class GlobalExceptionHandler
{
    private readonly RequestDelegate _next;
    private readonly IHostEnvironment _env;

    public GlobalExceptionHandler(RequestDelegate next, IHostEnvironment env)
    {
        _next = next;
        _env = env;
    }

    public async Task InvokeAsync(HttpContext httpContext)
    {
        try
        {
            await _next.Invoke(httpContext);
        }
        catch (SqlException ex) when (ex.Number == 51000)
        {
            await HandleExceptionAsync(httpContext, ex, HttpStatusCode.Conflict);
        }
        catch (Exception ex)
        {
            await HandleExceptionAsync(httpContext, ex, HttpStatusCode.InternalServerError);
        }
    }

    private async Task HandleExceptionAsync(HttpContext context, Exception ex, HttpStatusCode code)
    {
        var response = context.Response;
        response.ContentType = "application/json";
        response.StatusCode = (int)code;
        var allMessageText = GetFullMessage(ex);

        var details = _env.IsDevelopment() ? ex.StackTrace : string.Empty;

        await response.WriteAsync(JsonConvert.SerializeObject(
            new BaseResponse(
                code,
                allMessageText,
                string.IsNullOrEmpty(details)
                    ? string.Empty
                    : details)
        ));
    }

    private string GetFullMessage(Exception ex)
    {
        if (ex.InnerException != null)
        {
            return ex.Message + "; " + GetFullMessage(ex.InnerException);
        }

        return ex.Message;
    }
}