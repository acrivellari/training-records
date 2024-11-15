using Microsoft.AspNetCore.Http;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using TrainingRecords.Core.Shared.Models.Generic;
using UAParser;

namespace TrainingRecords.Core.Shared.Helpers;

public class ConnectionHelper
{
    /// <summary>
    /// Gets the details of the clients making the request
    /// </summary>
    /// <param name="request">HttpRequest object of the current request</param>
    /// <returns>
    /// ConnectionDetail object
    /// </returns>
    public static ConnectionDetail GetConnectionDetail(HttpRequest request)
    {
        ConnectionDetail connection = new ConnectionDetail();
        BrowserDetail browser = GetBrowserInfo(request);
        OSDetail os = GetOsDetail(request);
        string ip = GetIpAddress(request);

        connection.ClientBrowserName = browser.Name;
        connection.ClientBrowserVersion = browser.GetFullVersion();
        connection.IsLocalConnection = IsLocalConnection(ip);
        connection.ClientIpAddress = ip;
        connection.ClientOsName = os.Name;
        connection.ClientOsVersion = os.Version;
        connection.ClientLanguage = GetClientLanguage(request);
        connection.ClusterNumber = GetClusterNumber(request);
        connection.UserAgent = request.Headers["User-Agent"];

        return connection;
    }

    /// <summary>
    /// Gets the IP address of the clients making the request
    /// </summary>
    /// <param name="request">HttpRequest object of the current request</param>
    /// <returns>
    /// String IP address
    /// </returns>
    public static string GetIpAddress(HttpRequest request)
    {
        // RemoteIp = client PC address
        // AddressFamily = server address

        //string AddressFamily = Dns.GetHostEntry(Dns.GetHostName()).AddressList[1].MapToIPv4().ToString();
        string RemoteIp = request.HttpContext.Connection.RemoteIpAddress.MapToIPv4().ToString();

        return RemoteIp;
    }

    /// <summary>
    /// Gets the clients' name making the request
    /// </summary>
    /// <param name="IpAddress">IP address of the client that makes the request</param>
    /// <returns>
    /// String host name
    /// </returns>
    [Obsolete("GetHostNameByIp is deprecated bacause it takes too long to be executed", true)]
    public static string GetHostNameByIp(string IpAddress)
    {
        try
        {
            return Dns.GetHostEntry(IpAddress).HostName;
        }
        catch (Exception e)
        {
            string message = e.Message;
            return null;
        }
    }

    /// <summary>
    /// Gets the cluster number that answers the client request
    /// </summary>
    /// <param name="request">HttpRequest object of the current request</param>
    /// <returns>
    /// The cluster number
    /// </returns>
    public static int GetClusterNumber(HttpRequest request)
    {
        // LocalIp = server address
        string LocalIp = request.HttpContext.Connection.LocalIpAddress.MapToIPv4().ToString();
        string serverNode = Environment.MachineName;

        if (serverNode == null)
        {
            return -1;
        }

        switch (serverNode.ToLower())
        {
            case "v000iis1":
                return 1;
            case "v000iis2":
                return 2;
            case "v000iis3":
                return 3;
            case "v000iis4":
                return 4;
            case "v016iist":
                return 0;
            default:
                return -1;
        }
    }

    /// <summary>
    /// Gets the web system root address that answers the client request
    /// </summary>
    /// <param name="request">HttpRequest object of the current request</param>
    /// <returns>
    /// String
    /// </returns>
    public static string GetWebRoot(HttpRequest request)
    {
        int clusterNumber = GetClusterNumber(request);

        if (clusterNumber > 0)
        {
            return "https://work.maschionet.com";
        }

        return "localhost:8080"; //"http://work-test.maschionet.com";
    }

    /// <summary>
    /// Checks if the current request comes from within the company or not
    /// </summary>
    /// <param name="IpAddress">IP address of the client that makes the request</param>
    /// <returns>
    /// A boolean response
    /// </returns>
    public static bool IsLocalConnection(string IpAddress)
    {
        if (IpAddress.StartsWith("10.")
            || IpAddress.StartsWith("172.20.")
            || IpAddress.StartsWith("192.168.")
            || IpAddress.StartsWith("127.0.0.1")
            || IpAddress.Equals("localhost")
            || IpAddress.Equals("::1")
            || IpAddress.Equals("0.0.0.1")
            || IpAddress.Equals("212.131.239.252"))
        {
            return true;
        }

        return false;
    }

    /// <summary>
    /// Gets the client's browser details
    /// </summary>
    /// <param name="request">HttpRequest object of the current request</param>
    /// <returns>
    /// BrowserDetail object
    /// </returns>
    public static BrowserDetail GetBrowserInfo(HttpRequest request)
    {
        var userAgent = request.Headers["User-Agent"];
        string uaString = Convert.ToString(userAgent[0]);
        var uaParser = Parser.GetDefault();
        ClientInfo clientInfo = uaParser.Parse(uaString);

        BrowserDetail detail = new BrowserDetail();
        detail.Name = clientInfo.UA.Family;
        detail.MajorVersion = clientInfo.UA.Major;
        detail.MinorVersion = clientInfo.UA.Minor;
        detail.PatchVesrion = clientInfo.UA.Patch;
        return detail;
    }

    /// <summary>
    /// Gets the client's OS details
    /// </summary>
    /// <param name="request">HttpRequest object of the current request</param>
    /// <returns>
    /// OSDetail object
    /// </returns>
    public static OSDetail GetOsDetail(HttpRequest request)
    {
        var userAgent = request.Headers["User-Agent"];
        string uaString = Convert.ToString(userAgent[0]);
        var uaParser = Parser.GetDefault();
        ClientInfo clientInfo = uaParser.Parse(uaString);

        OSDetail detail = new OSDetail();
        detail.Device = clientInfo.Device.Family;
        detail.Name = clientInfo.OS.Family;
        detail.Version = clientInfo.OS.Major;
        return detail;
    }

    /// <summary>
    /// Gets the client's language settings
    /// </summary>
    /// <param name="request">HttpRequest object of the current request</param>
    /// <returns>
    /// The client's language in ISO2 format (two lower letters format)
    /// </returns>
    public static string GetClientLanguage(HttpRequest request)
    {
        var languages = request.GetTypedHeaders().AcceptLanguage;
        if (languages == null || languages.Count == 0)
        {
            return null;
        }

        string lang = languages[0].Value
            .ToString()
            .ToLowerInvariant()
            .Trim();

        if ("".Equals(lang))
        {
            return null;
        }

        CultureInfo cultureInfo = new CultureInfo(lang);
        return cultureInfo.TwoLetterISOLanguageName;
    }
}