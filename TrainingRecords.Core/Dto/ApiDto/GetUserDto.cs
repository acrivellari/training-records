using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrainingRecords.Core.Dto.ApiDto;
public class GetUserDtoRequest
{
    [Required]
    public string Username { get; set; }
    [Required]
    public string Password { get; set; }
}

public class GetUserDtoResponse
{
    [Required, NotNull]
    public string Token { get; set; }
}