#ifndef WVSIGNUP_H
#define WVSIGNUP_H

#include <QWidget>
#include <QLineEdit>

class WV_Signup : public QWidget {
    Q_OBJECT
private :
    QLineEdit* username;
    QLineEdit* password;
    QLineEdit* name;
    QLineEdit* surname;
public :
    WV_Signup(QWidget* = nullptr);
    QStringList getCredentials() const;
    Q_SIGNAL void sendRegister();
};

#endif
