using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TrainingRecords.Core.Services.Interfaces;

namespace TrainingRecords.Core.Services;

public class CurrentUserService : ICurrentUserService
{
    public int UserId => throw new NotImplementedException();

    public string UserName => throw new NotImplementedException();

    public string Password => throw new NotImplementedException();

    public IReadOnlyCollection<string> Roles => throw new NotImplementedException();

    public string IPv4Address => throw new NotImplementedException();
}
