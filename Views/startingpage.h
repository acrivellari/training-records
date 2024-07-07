#ifndef StartingPage_H
#define StartingPage_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#include "MyDialog.h"

namespace Views
{

    enum DialogTypes
    {
        Signin,
        Signup,
        SigninSuccess,
        SigninFailure,
        SignupSuccess,
        SignupFailure
    };

    class StartingPage : public QWidget
    {
        Q_OBJECT

        QPushButton * signinBtn, * signupBtn, *signinOkBtn, *signupOkBtn;
        MyDialog * signinDialog, * signupDialog, * successDialog, * failureDialog;
        QLabel *successText, *errorText;
        QLineEdit *signinUser, *signinPwd, *signupName, *signupSurname, *signupEmail, *signupUser, *signupPwd;


        bool isBusy = false;

        void initSigninDialog();
        void initSignupDialog();
        void initSuccessDialog();
        void initFailureDialog();

    public:
        StartingPage(QWidget *parent=nullptr);
        ~StartingPage(void);

        bool get_IsBusy(void) const;
        QString get_signinUser(void) const;
        QString get_signinPwd(void) const;
        QString get_signupName(void) const;
        QString get_signupSurname(void) const;
        QString get_signupEmail(void) const;
        QString get_signupUser(void) const;
        QString get_signupPwd(void) const;
        void set_IsBusy(bool);
        void set_IsBusy_login(bool);
        void set_IsBusy_signup(bool);
        void showDialog(DialogTypes);
        void closeDialog();

    signals:
        void signinPopup(void);
        void signupPopup(void);
        void signinRequest(void);
        void forgotPassword(void);
        void signupRequest(void);
        void closedDialog(void);

    public slots:
        void successAuth(void);
        void errorAuth(void);
        void validateSignin(void);
        void validateSignup(void);
    };
}

#endif // StartingPage_H
