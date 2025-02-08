using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TrainingRecords.Core.Dto.ApiDto;

namespace TrainingRecords.Core.Dto;

public record GenericApiResponseDto<TPayload>
{
    [Required, AllowNull]
    public TPayload? Payload { get; set; }
    [Required, AllowNull]
    public ErrorResponseDto? Error { get; set; }
}

public record ErrorResponseDto
{
    [Required]
    public string Code { get; set; }
    [Required]
    public string Message { get; set; }
}