namespace TrainingRecords.Core.Shared.Models.Generic;

public class ConnectionDetail
{
    public bool IsLocalConnection { get; set; }
    public string ClientIpAddress { get; set; }
    public string ClientLanguage { get; set; }
    public string ClientOsName { get; set; }
    public string ClientOsVersion { get; set; }
    public string ClientBrowserName { get; set; }
    public string ClientBrowserVersion { get; set; }
    public int ClusterNumber { get; set; }
    public string UserAgent { get; set; }
}