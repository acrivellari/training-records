using System.Net;

namespace TrainingRecords.WebApi.Models.Common;

public class BaseResponse
{
    public HttpStatusCode StatusCode { get; }

    public string Message { get; }

    public string Details { get; }

    public BaseResponse(HttpStatusCode statusCode, string message, string details)
    {
        StatusCode = statusCode;
        Message = message;
        Details = details;
    }
}