#include "../awsio.h"

AwsIO::AwsIO() : a(1) {}

void AwsIO::load(std::vector<Training*>& m, std::string s) const
{

}

bool AwsIO::save(const std::vector<Training*>& m, std::string s) const
{
    return true;
}
