#ifndef USERDAO_H
#define USERDAO_H

#include <QSqlDatabase>
#include "../Resources/User.h"

namespace Models
{
    namespace DAOs
    {
        class UserDAO
        {
        private:
            static QString GET_USER_BY_USERNAME_STATEMENT;
            static QString INSERT_NEW_USER;
        public:
            static Resources::User* getUserByUsername(const QString& user, const QSqlDatabase* conn, const QString& schema);
            static bool insertNewUser(Resources::User*, const QSqlDatabase*, const QString& schema);
        };

    }
}

#endif // USERDAO_H
