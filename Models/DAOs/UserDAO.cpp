#include "UserDAO.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

QString Models::DAOs::UserDAO::GET_USER_BY_USERNAME_STATEMENT="SELECT * FROM [schema].users WHERE username=?";

QString Models::DAOs::UserDAO::INSERT_NEW_USER = "INSERT INTO [schema].users (username, name, surname, password, email) VALUES ( ?, ?, ?, ?, :email)";

Models::Resources::User* Models::DAOs::UserDAO::getUserByUsername(const QString& username, const QSqlDatabase* conn, const QString& schema)
{
    Resources::User* res = nullptr;

    QSqlQuery query(*conn);
    query.prepare(QString(GET_USER_BY_USERNAME_STATEMENT).replace("[schema]", schema));
    query.addBindValue(username);
    if (query.exec())
    {
        if (query.size() > 0) {
            query.first();
            res = new Resources::User
                (
                query.value("id").toInt(),
                query.value("username").toString(),
                query.value("password").toString(),
                query.value("name").toString(),
                query.value("surname").toString(),
                query.value("email").toString(),
                query.value("creation_date").toDateTime()
                );
        }
    }
    else
    {
        throw std::runtime_error("DB error");
    }


    return res;
}

bool Models::DAOs::UserDAO::insertNewUser(Resources::User* user, const QSqlDatabase* conn, const QString& schema)
{
    QSqlQuery query(*conn);
    QString statement = QString(INSERT_NEW_USER).replace("[schema]", schema);

    QString email = user -> get_email();
    if (email == "")
    {
        statement.replace(":email", "NULL");
    }
    else
    {
        statement.replace(":email", email);
    }

    query.prepare(statement);
    query.addBindValue(user -> get_username());
    query.addBindValue(user -> get_name());
    query.addBindValue(user -> get_surname());
    query.addBindValue(user -> get_password());

    bool ret = query.exec();
    if (!ret) {
        qDebug() << "Failed to insert email:" << query.lastError().text();
    }

    return ret;
}
