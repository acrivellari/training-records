#include "../../widgetView/wvAuth.h"
#include <QIcon>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCloseEvent>
#include <QMessageBox>

WV_Auth::WV_Auth(QWidget* p) : QWidget{p}, loginWindow{new WV_Login{this}}, signupWindow{new WV_Signup{this}} {
    QVBoxLayout* layout;
    QPushButton* login;
    QPushButton* signup;

    layout = new QVBoxLayout{this};
    login = new QPushButton{this};
    signup = new QPushButton{this};
    login -> setText("LOGIN");
    
    login -> setStyleSheet("padding: 20px 5px 20px 5px; font-size:20px; margin: 0px 20px 0px 20px;");
    signup -> setText("SIGNUP");
    signup -> setStyleSheet("padding: 20px 5px 20px 5px; font-size:20px; margin: 0px 20px 0px 20px;");

    layout -> addWidget(login);
    layout -> addWidget(signup);
    setLayout(layout);

    setWindowTitle("Authentication");
    resize(400,400);
    
    QObject::connect(loginWindow, &WV_Login::sendLogin, this, &WV_Auth::sendLogin);
    QObject::connect(signupWindow, &WV_Signup::sendRegister, this, &WV_Auth::sendRegister);
    QObject::connect(login, &QPushButton::clicked, this, &WV_Auth::showLogin);
    QObject::connect(signup, &QPushButton::clicked, this, &WV_Auth::showSignup);


}

void WV_Auth::getCredentialsLogin(std::string& user, std::string& pass) const {
    QStringList credentials = loginWindow -> getCredentials();
    if (credentials.empty() == false){
        user = credentials.at(0).toStdString();
        pass = credentials.at(1).toStdString();
    }
}

void WV_Auth::getCredentialsSignup(std::string& user, std::string& pass, std::string& name, std::string& surname) const {
    QStringList credentials = signupWindow -> getCredentials();
    if (credentials.empty() == false) {
        user = credentials.at(0).toStdString();
        pass = credentials.at(1).toStdString();
        name = credentials.at(2).toStdString();
        surname = credentials.at(3).toStdString();
    }
}

void WV_Auth::setVisibilityLogin(bool show) {
    if (show)
        loginWindow -> show();
    else
        loginWindow -> hide();
}

void WV_Auth::setVisibilitySignup(bool show) {
    if (show)
        signupWindow -> show();
    else
        signupWindow -> hide();
}