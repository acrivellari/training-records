#include "AppService.h"

Models::AppService::AppService() : dbService (new DatabaseService()), authManager(new AuthManager(dbService)) {}

Models::AppService::~AppService() {}

bool Models::AppService::processSignin(QString user, QString pwd)
{
    return authManager -> processSignin(user, pwd);
}

bool Models::AppService::processSignup(QString name, QString surname, QString email, QString user, QString pwd)
{
    return authManager -> processSignup(name, surname, email, user, pwd);
}
