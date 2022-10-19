#ifndef WVAUTH_H
#define WVAUTH_H

#include <QWidget>
#include "wvLogin.h"
#include "wvSignup.h"

class WV_Auth : public QWidget {
    Q_OBJECT
private :
    WV_Login* loginWindow;
    WV_Signup* signupWindow;
public :
    WV_Auth(QWidget* = nullptr);

    void getCredentialsLogin(std::string&, std::string&) const;
    void getCredentialsSignup(std::string&, std::string&, std::string&, std::string&) const;
    void setVisibilityLogin(bool);
    void setVisibilitySignup(bool);

    Q_SIGNAL void sendLogin();
    Q_SIGNAL void sendRegister();
};

#endif
