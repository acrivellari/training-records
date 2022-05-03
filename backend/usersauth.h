#ifndef USERSAUTH_H
#define USERSAUTH_H

#include <string>

class UsersAuth {
private:
    std::string pathDB;
public:
    UsersAuth(std::string);
    bool giveCredentials(std::string, std::string) const;
    bool addCredentials(std::string, std::string);
};

#endif // USERSAUTH_H
