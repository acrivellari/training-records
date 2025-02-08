using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using System.Reflection;
using System.Runtime.InteropServices;
using System;
using System.IO;
using Newtonsoft.Json;
using TrainingRecords.Core.Interfaces;
using System.Security.Cryptography;
using System.Text;
using TrainingRecords.Core.Services.Interfaces;
using TrainingRecords.Core.Dto;
using TrainingRecords.Core.Dto.ApiDto;
using TrainingRecords.Core.Shared.Interfaces;

namespace TrainingRecords.WebApi.Controllers;


/// <summary>
/// Gives informations about the API environment
/// </summary>
[Authorize]
[ApiController]
[Route("api/[controller]")]
public class UserController : ControllerBase
{
    private readonly IUserService _service;
    private readonly IJwtTokenService _tokenService;

    public UserController(IUserService service, IJwtTokenService jwtTokenService)
    {
        this._service = service;
        this._tokenService = jwtTokenService;
    }

    [AllowAnonymous]
    [HttpPost("login")]
    [Consumes("application/json")]
    public async Task<ActionResult> Authenticate(GetUserDtoRequest request)
    {
        var user = await _service.CheckCredentials(request.Username, request.Password);
        var response = new GenericApiResponseDto<dynamic> { Payload = null, Error = null };

        if (user == null) { 
            return Unauthorized(response with { Error = new ErrorResponseDto { Code = "412", Message = "Wrong credentials" } });
        }
        else
        {
            (var token, var expires_in) = _tokenService.GenerateAccessToken(user.Id, user.Name, user.Password, new List<string>() { user.Email });
            return Ok(response with { Payload = new { token, expires_in } });
        }
    }

    [HttpGet]
    public async Task<ActionResult> GetUserByToken()
    {
        var token = Request.Headers["Authorization"].ToString().Split(" ")[1];
        var userId = _tokenService.GetTokenCredentials(token).Item1;
        var username = await _service.GetUsernameById(userId);

        if (username is null)
        {
            return Unauthorized(new GenericApiResponseDto<dynamic> { Payload = null, Error = new ErrorResponseDto { Code = "411", Message = "Wrong token" } });
        }
        return Ok(new GenericApiResponseDto<dynamic> { Payload = new { username }, Error = null });
    }
}