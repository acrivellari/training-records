#ifndef USER_H
#define USER_H

#include "../../backend/backendException.h"
#include <QWidget>
#include <QLineEdit>

class User : public QWidget{
    Q_OBJECT
private:
    QLineEdit* nameLineEdit;
    QLineEdit* surnameLineEdit;
    QLineEdit* usernameLineEdit;
    QLineEdit* passwordLineEdit;
public:
    User(QWidget*);
    void setName(QString);
    void setSurname(QString);
    void setUsername(QString);
    void setPassword(QString);

    Q_SLOT void updateCredentials();
};

#endif