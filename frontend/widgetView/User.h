#ifndef USER_H
#define USER_H

#include "../../backend/backendException.h"
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class User : public QWidget{
    Q_OBJECT
private:
    QPushButton* saveButton;
    QLineEdit* nameLineEdit;
    QLineEdit* surnameLineEdit;
    QLineEdit* usernameLineEdit;
    QLineEdit* passwordLineEdit;
public:
    User(QWidget*);
    void buildPage();
    void setName(QString);
    void setSurname(QString);
    void setUsername(QString);
    void setPassword(QString);

    Q_SIGNAL void reqUpdateCredentials();
};

#endif