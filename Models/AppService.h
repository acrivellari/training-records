#ifndef APPSERVICE_H
#define APPSERVICE_H

#include "AuthManager.h"
#include "DatabaseService.h"

namespace Models {
    class AppService {
    private:
        DatabaseService *dbService;
        AuthManager *authManager;
    public:
        AppService();
        ~AppService();
        bool processSignin(QString user, QString pwd);
        bool processSignup(QString name, QString surname, QString email, QString user, QString pwd);
    };
}

#endif // APPSERVICE_H

