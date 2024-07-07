#include "AuthManager.h"

#include <QCryptographicHash>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

Models::AuthManager::AuthManager(DatabaseService* dbService_passed) : dbService(dbService_passed) {}

Models::AuthManager::~AuthManager() {}

bool Models::AuthManager::processSignin(QString username, QString pwd)
{
    Resources::User* user = dbService -> getUserByUsername(username);
    return (user != nullptr && user -> get_password() == QCryptographicHash::hash(pwd.toUtf8(), QCryptographicHash::Sha3_256).toHex());
}

bool Models::AuthManager::processSignup(QString name, QString surname, QString email, QString user, QString pwd)
{
    if (dbService -> getUserByUsername(user) != nullptr)
    {
        return false;
    }

    QString sanitized_email = "";
    if (isValidEmail(email)){
        sanitized_email = email.trimmed();
    }


    return dbService -> insertNewUser(
        new Resources::User(user,
            QCryptographicHash::hash(pwd.toUtf8(), QCryptographicHash::Sha3_256).toHex(),
            name, surname, sanitized_email
        )
    );
}


bool Models::AuthManager::isValidEmail(const QString &email) const
{
    QRegularExpression emailRegex(R"((^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$))");
    QRegularExpressionValidator validator(emailRegex);
    int pos = 0;

    return validator.validate(const_cast<QString &>(email), pos) == QValidator::Acceptable;
}
