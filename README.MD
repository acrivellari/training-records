# Training Records Project

Project in C#

Api in ASP.NET - NET6
Database used is PostgresSQL
In TrainingRecords.WebApi create a file appsettings.Development.json with :

{
  "Logging": {
    "LogLevel": {
      "Default": "Information",
      "Microsoft.AspNetCore": "Warning"
    }
  },
  "JWTTokenConfig": {
    "secret": "",
    "RefreshTokenSecret": "",
    "issuer": "",
    "audience": "",
    "accessTokenExpiration": 60,
    "refreshTokenExpiration": 10080
  },
  "ConnectionStrings": {
    "Db": ""
  }
}


---
compile the empty strings