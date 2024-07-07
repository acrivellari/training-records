#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include "DatabaseService.h"

namespace Models {
    class AuthManager {
    private:
        DatabaseService* dbService;
        bool isValidEmail(const QString &email) const;
    public:
        AuthManager(DatabaseService*);
        ~AuthManager();

        bool processSignin(QString username, QString pwd);
        bool processSignup(QString name, QString surname, QString email, QString username, QString pwd);
    };
}

#endif // AUTHMANAGER_H

