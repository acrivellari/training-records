#ifndef WVLOGIN_H
#define WVLOGIN_H

#include <QWidget>
#include <QLineEdit>

class WV_Login : public QWidget {
    Q_OBJECT
private :
    QLineEdit* username;
    QLineEdit* password;
public :
    WV_Login(QWidget* = nullptr);
    QStringList getCredentials() const;
    Q_SIGNAL void sendLogin();
    Q_SIGNAL void showSignup();
};

#endif
