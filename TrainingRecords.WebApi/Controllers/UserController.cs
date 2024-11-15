using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using System.Reflection;
using System.Runtime.InteropServices;
using System;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using TrainingRecords.Core.Dto.ApiRequests;
using TrainingRecords.Core.Services.Interfaces;
using TrainingRecords.Core.Interfaces;


namespace TrainingRecords.WebApi.Controllers;


/// <summary>
/// Gives informations about the API environment
/// </summary>
[Authorize]
[ApiController]
[Route("api/[controller]")]
public class UserController : ControllerBase
{
    private readonly IUserRepository _service;

    public UserController(IUserRepository service)
    {
        this._service = service;
    }

    [AllowAnonymous]
    [HttpPost("login")]
    [Consumes("application/json")]
    public async Task<ActionResult> GetUser(GetUserDto request)
    {
        
        return Ok(await _service.Prova());
    }

}