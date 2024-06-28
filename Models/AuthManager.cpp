#include "AuthManager.h"



Models::AuthManager::AuthManager()
{

}

Models::AuthManager::~AuthManager()
{

}

bool Models::AuthManager::processSignin(std::string user, std::string pwd)
{
    return user == pwd;
}

bool Models::AuthManager::processSignup(std::string name, std::string surname, std::string user, std::string pwd)
{
    return user == pwd;
}
