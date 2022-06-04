#include "../../widgetView/wvAuth.h"

WV_Auth::WV_Auth(QWidget* p) : QWidget{p}, loginWindow{new WV_Login{this}}, signupWindow{new WV_Signup{this}} {
    loginWindow -> show();
    QObject::connect(loginWindow, &WV_Login::sendLogin, this, &WV_Auth::sendLogin);
}

void WV_Auth::getCredentials(std::string& user, std::string& pass) const {
    QStringList credentials = loginWindow -> getCredentials();
    user = credentials.at(0).toStdString();
    pass = credentials.at(1).toStdString();
}

void WV_Auth::hideLogin() {
    loginWindow -> hideLogin();
}