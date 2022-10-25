#include "../../widgetView/User.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

User::User(QWidget* p) : QWidget(p) {
    buildPage();
    QObject::connect(saveButton, &QPushButton::clicked, this, &User::reqUpdateCredentials);
}

void User::buildPage() {
    QVBoxLayout* mainLayout = new QVBoxLayout{this};
    QHBoxLayout* nameLayout = new QHBoxLayout{this};
    QHBoxLayout* surnameLayout = new QHBoxLayout{this};
    QHBoxLayout* usernameLayout = new QHBoxLayout{this};
    QHBoxLayout* passwordLayout = new QHBoxLayout{this};
    QLabel* nameLabel = new QLabel{this};
    QLabel* surnameLabel = new QLabel{this};
    QLabel* usernameLabel = new QLabel{this};
    QLabel* passwordLabel = new QLabel{this};
    nameLineEdit = new QLineEdit{this};
    surnameLineEdit = new QLineEdit{this};
    usernameLineEdit = new QLineEdit{this};
    passwordLineEdit = new QLineEdit{this};
    saveButton = new QPushButton{this};

    nameLabel -> setText("Name:  ");
    surnameLabel -> setText("Surname:  ");
    usernameLabel -> setText("Username:  ");
    usernameLineEdit -> setReadOnly(true);
    usernameLineEdit -> setStyleSheet("background-color: #dddded; color : #828285;");
    passwordLabel -> setText("Password:  ");
    saveButton -> setText("Save Credentials");
    
    setLayout(mainLayout);
    nameLayout -> addWidget(nameLabel);
    nameLayout -> addWidget(nameLineEdit);
    mainLayout -> addLayout(nameLayout);
    surnameLayout -> addWidget(surnameLabel);
    surnameLayout -> addWidget(surnameLineEdit);
    mainLayout -> addLayout(surnameLayout);
    usernameLayout -> addWidget(usernameLabel);
    usernameLayout -> addWidget(usernameLineEdit);
    mainLayout -> addLayout(usernameLayout);
    passwordLayout -> addWidget(passwordLabel);
    passwordLayout -> addWidget(passwordLineEdit);
    mainLayout -> addLayout(passwordLayout);
    mainLayout -> addWidget(saveButton);

    setWindowTitle("User Page");
    setWindowFlag(Qt::Window);
    setWindowModality(Qt::WindowModal);
}

QString User::getName() const {
    return nameLineEdit -> text();
}

QString User::getSurname() const {
    return surnameLineEdit -> text();
}

QString User::getUsername() const {
    return usernameLineEdit -> text();
}

QString User::getPassword() const {
    return passwordLineEdit -> text();
}

void User::setName(QString n) {
    nameLineEdit -> setText(n);
}

void User::setSurname(QString s) {
    surnameLineEdit -> setText(s);
}

void User::setUsername(QString u) {
    usernameLineEdit -> setText(u);
}

void User::setPassword(QString p) {
    passwordLineEdit -> setText(p);
}

