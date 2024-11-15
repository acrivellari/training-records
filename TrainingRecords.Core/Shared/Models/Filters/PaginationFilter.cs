namespace TrainingRecords.Core.Shared.Models.Filters;

public class PaginationFilter
{
    public int? p { get; set; }

    public int? ps { get; set; }

    public PaginationFilter()
    {
        p = 1;
        ps = 10;
    }

    public PaginationFilter(int? pageNumber, int? pageSize)
    {
        if (pageNumber is not null && pageSize is not null)
        {
            p = pageNumber < 1 ? 1 : pageNumber;
            ps = pageSize < 1 ? 1 : pageSize;
        }
    }

    public int GetPageNumberInt() => p.Value;

    public int GetPageSizeInt() => ps.Value;

    public bool IsSet() => p is not null && ps is not null;

    public string Sql => IsSet()
        ? @$"OFFSET {ps * (p - 1)} ROWS 
             FETCH NEXT {ps} ROWS ONLY"
        : string.Empty;

}