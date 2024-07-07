#include "User.h"

Models::Resources::User::User(int id_value, QString username_value, QString password_value, QString name_value, QString surname_value, QString email_value, QDateTime creation_date_value)
    : id(id_value), username(username_value), password(password_value), name(name_value), surname(surname_value), email(email_value), creation_date(creation_date_value) {}

Models::Resources::User::User(QString username_value, QString password_value, QString name_value, QString surname_value, QString email_value)
    : username(username_value), password(password_value), name(name_value), surname(surname_value), email(email_value)
{
    id = -1;
    creation_date = QDateTime::currentDateTime();
}

int Models::Resources::User::get_id() const
{
    return id;
}

QString Models::Resources::User::get_username() const
{
    return username;
}

QString Models::Resources::User::get_password() const
{
    return password;
}

QString Models::Resources::User::get_name() const
{
    return name;
}

QString Models::Resources::User::get_surname() const
{
    return surname;
}

QString Models::Resources::User::get_email() const
{
    return email;
}

QDateTime Models::Resources::User::get_creation_date() const
{
    return creation_date;
}

