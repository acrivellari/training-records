namespace TrainingRecords.Core.Shared.Models.Generic;

public class BrowserDetail
{
    public string Name { get; set; }
    public string MajorVersion { get; set; }
    public string MinorVersion { get; set; }
    public string PatchVesrion { get; set; }

    public string GetFullVersion()
    {
        if ((MinorVersion == null || PatchVesrion == null) && MajorVersion != null)
        {
            return MajorVersion;
        }
        else if (MajorVersion == null)
        {
            return null;
        }

        return string.Format("{0}.{1}.{2}",
            MajorVersion, MinorVersion, PatchVesrion);
    }
}