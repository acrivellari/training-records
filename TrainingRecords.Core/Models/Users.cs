using Dapper.Contrib.Extensions;

namespace TrainingRecords.Core.Models;

[Table("dev.users")]
public class Users
{
    [Key]
    public int Id { get; set; }
    public string Username { get; set; }
    public string Name { get; set; }
    public string Surname { get; set; }
    public string Password { get; set; }
    public string Email { get; set; }
    public DateTime CreationDate { get; set; }
}
