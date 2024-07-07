#ifndef DATABASESERVICE_H
#define DATABASESERVICE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include "Resources/User.h"
#include "DAOs/UserDAO.h"


namespace Models
{
    class DatabaseService
    {
    public:
        DatabaseService();
        Resources::User* getUserByUsername(const QString&);
        bool insertNewUser(Resources::User*);
    private:
        QSqlDatabase conn;
        QString schema;
        void readConfigFile(const QString& filename, QStringList* expected_params, QMap<QString, QString>* params) const noexcept(false);
    };
}
#endif // DATABASESERVICE_H
