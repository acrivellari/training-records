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


namespace TrainingRecords.WebApi.Controllers;


    /// <summary>
    /// Gives informations about the API environment
    /// </summary>
    [Authorize]
    [ApiController]
    [Route("api/[controller]")]
    public class AboutController : ControllerBase
    {
        private readonly IWebHostEnvironment _env;

        public AboutController(IWebHostEnvironment env)
        {
            this._env = env;
        }

    [AllowAnonymous]
    [HttpGet]
        public ActionResult GetApiInfo()
        {
            string serverName = Environment.MachineName;
            string osPlatform = RuntimeInformation.OSDescription;
            string netCoreVersion = RuntimeInformation.FrameworkDescription;
            string appVersion = Assembly.GetEntryAssembly().GetName().Version.ToString();
            string informationVersion = Assembly.GetEntryAssembly().GetCustomAttribute<AssemblyInformationalVersionAttribute>().InformationalVersion;
            DateTime appLastBuildTime = GetLastBuildTime();

            return Ok(new
            {
                machineName = serverName,
                machineOs = osPlatform,
                netCoreVersion = netCoreVersion,
                appVersion = informationVersion,
                lastBuild = appLastBuildTime
            });
        }

        private DateTime GetLastBuildTime()
        {
            const int peHeaderOffset = 60;
            const int linkerTimestampOffset = 8;

            byte[] bytes = new byte[2048];
            using (FileStream file = new FileStream(Assembly.GetEntryAssembly().Location, FileMode.Open, FileAccess.Read, FileShare.ReadWrite))
            {
                file.Read(bytes, 0, bytes.Length);
            }

            Int32 headerPos = BitConverter.ToInt32(bytes, peHeaderOffset);
            Int32 secondsSince1970 = BitConverter.ToInt32(bytes, headerPos + linkerTimestampOffset);
            DateTime dt = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
            DateTime dateTimeUTC = dt.AddSeconds(secondsSince1970);
            DateTime localTime = TimeZoneInfo.ConvertTimeFromUtc(dateTimeUTC, TimeZoneInfo.Local);

            return localTime;
        }
    }