#include "../../widgetView/wvAuth.h"
#include <QIcon>

WV_Auth::WV_Auth(QWidget* p, std::string path) : QWidget{p}, loginWindow{new WV_Login{this}}, signupWindow{new WV_Signup{this}} {
    setWindowIcon(QIcon
    (QString::fromStdString(path) + "icon.png")
        );

    loginWindow -> show();

    QObject::connect(loginWindow, &WV_Login::sendLogin, this, &WV_Auth::sendLogin);
    QObject::connect(loginWindow, &WV_Login::showSignup, this, &WV_Auth::login2Signup);
}

void WV_Auth::getCredentials(std::string& user, std::string& pass) const {
    QStringList credentials = loginWindow -> getCredentials();
    user = credentials.at(0).toStdString();
    pass = credentials.at(1).toStdString();
}

void WV_Auth::hideLogin() {
    loginWindow -> hide();
}

void WV_Auth::login2Signup() {
    loginWindow -> hide();
    signupWindow -> show();
}