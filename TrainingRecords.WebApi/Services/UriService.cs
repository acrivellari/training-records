using Microsoft.AspNetCore.WebUtilities;
using System.Reflection;
using TrainingRecords.Core.Shared.Helpers;
using TrainingRecords.Core.Shared.Models.Filters;
using TrainingRecords.WebApi.Services.Interfaces;

namespace TrainingRecords.WebApi.Services;

    public class UriService : IUriService
    {
        private readonly string _baseUri;
        private readonly HttpRequest _request;

        public UriService(string baseUri, HttpRequest request)
        {
            this._baseUri = baseUri;
            this._request = request;
        }

        public Uri GetPageUri
        (
            PaginationFilter pagination,
            SortingFilter sorting,
            IEntityFilterBase resultsFilter
        )
        {
            // Route of the current request
            string route = this._request.Path.Value;
            var _endpointUri = new Uri(string.Concat(_baseUri, route));
            // Add query string parameters for pagination
            var modifiedUri = QueryHelpers.AddQueryString(_endpointUri.ToString(), "p", pagination.p.ToString());
            modifiedUri = QueryHelpers.AddQueryString(modifiedUri, "ps", pagination.ps.ToString());
            // Add query string parameters for sorting
            if (sorting.IsSet())
            {
                modifiedUri = QueryHelpers.AddQueryString(modifiedUri, "s", sorting.s);
                modifiedUri = QueryHelpers.AddQueryString(modifiedUri, "o", sorting.o);
            }
            // Add query string parameters for result filtering
            if (resultsFilter != null)
            {
                if (resultsFilter.IsSet())
                {
                    foreach (PropertyInfo prop in resultsFilter.GetType().GetProperties())
                    {
                        if (resultsFilter.GetType().GetProperty(prop.Name).GetValue(resultsFilter, null) != null && !prop.Name.Equals("IsDeleted"))
                        {
                            modifiedUri = QueryHelpers.AddQueryString
                            (
                                modifiedUri,
                                prop.Name.ToLower(),
                                resultsFilter.GetType().GetProperty(prop.Name).GetValue(resultsFilter, null).ToString()
                            );
                        }
                    }
                }
            }
            return new Uri(modifiedUri);
        }

        public Uri GetEmergencyPwdResetUri(string requestToken)
        {
            string webRoot = ConnectionHelper.GetWebRoot(_request);
            // Link to the front end view
            var _endpointUri = new Uri(string.Concat(webRoot, "/forced-resetpwd?data=" + requestToken));
            return _endpointUri;
        }

        public Uri GetEmailVerificationUri(string requestToken)
        {
            string webRoot = ConnectionHelper.GetWebRoot(_request);
            // Link to the front end view
            var _endpointUri = new Uri(string.Concat(webRoot, "/account/verify-email?data=" + requestToken));
            return _endpointUri;
        }
    }