#ifndef USER_H
#define USER_H

#include <QWidget>
#include <QLineEdit>
#include "../backend/controller.h"

class User : public QWidget{
    Q_OBJECT
private:
    Controller* controller;
    QLineEdit* nameLineEdit;
    QLineEdit* surnameLineEdit;
    QLineEdit* usernameLineEdit;
    QLineEdit* passwordLineEdit;
public:
    User(QWidget* , Controller*);
    Q_SLOT void updateCredentials();
};

#endif