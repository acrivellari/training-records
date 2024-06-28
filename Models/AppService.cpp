#include "AppService.h"



Models::AppService::AppService()
{

}

Models::AppService::~AppService()
{

}

bool Models::AppService::processSignin(std::string user, std::string pwd)
{
    return authManager -> processSignin(user, pwd);
}

bool Models::AppService::processSignup(std::string name, std::string surname, std::string user, std::string pwd)
{
    return authManager -> processSignup(name, surname, user, pwd);
}
