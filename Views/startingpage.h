#ifndef StartingPage_H
#define StartingPage_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

#include "MyDialog.h"

namespace Views
{

    enum DialogTypes
    {
        Signin,
        Signup
    };

    class StartingPage : public QWidget
    {
        Q_OBJECT

        QPushButton * signinBtn, * signupBtn;
        MyDialog * signinDialog, * signupDialog;
        QMap<QString, QLineEdit*> textFields_signin;
        QMap<QString, QLineEdit*> textFields_signup;

        bool isBusy = false;

        void initSigninDialog();
        void initSignupDialog();

    public:
        StartingPage(QWidget *parent=nullptr);
        ~StartingPage(void);

        bool get_IsBusy(void) const;
        void set_IsBusy(bool);
        void showDialog(DialogTypes);
        void closeDialog();

    signals:
        void signinPopup(void);
        void signupPopup(void);
        void signinRequest(void);
        void forgotPassword(void);
        void signupRequest(void);
        void closedDialog(void);
    };
}

#endif // StartingPage_H
