#include "../awsio.h"

AwsIO::AwsIO() : a(1) {}

bool AwsIO::load() const
{
    return true;
}

bool AwsIO::save(std::vector<std::tuple<unsigned int, std::string, std::vector<std::tuple<std::string, std::string, bool> > > > &, std::vector<std::string> &)
{
    return true;
}

