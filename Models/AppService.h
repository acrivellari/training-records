#ifndef APPSERVICE_H
#define APPSERVICE_H

#include <string>
#include "AuthManager.h"

namespace Models {
    class AppService {
    private:
        AuthManager* authManager;
    public:
        AppService();
        ~AppService();
        bool processSignin(std::string user, std::string pwd);
        bool processSignup(std::string name, std::string surname, std::string user, std::string pwd);
    };
}

#endif // APPSERVICE_H

