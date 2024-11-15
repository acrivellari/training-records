using TrainingRecords.Core.Shared.Models.Filters;

namespace TrainingRecords.WebApi.Services.Interfaces;

public interface IUriService
{
    /// <summary>
    /// Creates the URI link to refer to another entity page (for paged responses)
    /// </summary>
    /// <param name="pagination">Pagination filters applied to the request</param>
    /// <param name="sorting">Sorting filters applied to the request</param>
    /// <param name="resultsFilter">Data filters applied to the request</param>
    /// <returns>
    /// The URI string that refers to a specific page of the current entity
    /// </returns>
    Uri GetPageUri
    (
        PaginationFilter pagination,
        SortingFilter sorting,
        IEntityFilterBase resultsFilter
    );

    /// <summary>
    /// Creates the URI link to refer to the endpoint to reset the password in case of stolen credentials
    /// </summary>
    /// <param name="requestToken">requestToken</param>
    /// <returns>
    /// Reset password URI link
    /// </returns>
    Uri GetEmergencyPwdResetUri(string requestToken);

    /// <summary>
    /// Creates the URI link to refer to the endpoint to verify e-mail address
    /// </summary>
    /// <param name="requestToken">requestToken</param>
    /// <returns>
    /// E-mail verification URI link
    /// </returns>
    Uri GetEmailVerificationUri(string requestToken);
}
