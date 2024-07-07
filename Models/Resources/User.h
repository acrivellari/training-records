#ifndef USER_H
#define USER_H

#include <QString>
#include <QDateTime>

namespace Models
{
    namespace Resources
    {
        class User
        {
        private:
            int id;
            QString username;
            QString password;
            QString name;
            QString surname;
            QString email;
            QDateTime creation_date;
        public:
            User(int id, QString username, QString password, QString name, QString surname, QString email, QDateTime creation_date);
            User(QString username, QString password, QString name, QString surname, QString email);

            int get_id() const;
            QString get_username() const;
            QString get_password() const;
            QString get_name() const;
            QString get_surname() const;
            QString get_email() const;
            QDateTime get_creation_date() const;
        };
    }
}

#endif // USER_H
