namespace TrainingRecords.Core.Shared.Models.Filters;

public class SortingFilter
{
    /// <summary>
    /// Property to use for sorting data
    /// </summary>
    public string s { get; set; } = null;

    /// <summary>
    /// Sorting order
    /// </summary>
    public string o { get; set; } = "asc";

    public bool IsSet() => s is not null;

    public string SqlOrder => o.Equals("asc") ? "asc" : "desc";
}