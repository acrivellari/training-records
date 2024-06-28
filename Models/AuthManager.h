#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <string>

namespace Models {
    class AuthManager {
    public:
        AuthManager();
        ~AuthManager();

        bool processSignin(std::string user, std::string pwd);
        bool processSignup(std::string name, std::string surname, std::string user, std::string pwd);
    };
}

#endif // AUTHMANAGER_H

