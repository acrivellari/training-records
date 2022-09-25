#ifndef USERSAUTH_H
#define USERSAUTH_H

#include <string>

class UsersAuth {
private:
    std::string pathDB;
    std::string name, surname, username, password;
public:
    UsersAuth(std::string);
    bool giveCredentials(std::string, std::string);
    bool addCredentials(std::string, std::string, std::string = "", std::string = "");
    bool changeCredentials(std::string, std::string, std::string, std::string, std::string);
    std::string getCredential(std::string) const;
};

#endif // USERSAUTH_H
