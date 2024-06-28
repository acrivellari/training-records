#include "StartingPage.h"

#include <QVBoxLayout>
#include <QDialog>

namespace Views
{
    StartingPage::StartingPage(QWidget *parent)
    : QWidget{parent}, signinDialog{new MyDialog{this}}, signupDialog{new MyDialog{this}}, successDialog{new MyDialog{this}}, failureDialog{new MyDialog{this}}
    {
        initSigninDialog();
        initSignupDialog();
        initSuccessDialog();
        initFailureDialog();

        QVBoxLayout* mainLayout = new QVBoxLayout{this};
        signinBtn = new QPushButton{"Sign In", this};
        signupBtn = new QPushButton{"Sign On", this};
        mainLayout -> addWidget(signinBtn);
        mainLayout -> addWidget(signupBtn);

        QObject::connect(signinBtn, &QPushButton::clicked, this, &StartingPage::signinPopup);
        QObject::connect(signupBtn, &QPushButton::clicked, this, &StartingPage::signupPopup);
        QObject::connect(signinDialog, &MyDialog::closedDialog, this, &StartingPage::closedDialog);
        QObject::connect(signupDialog, &MyDialog::closedDialog, this, &StartingPage::closedDialog);
    }

    StartingPage::~StartingPage(void) {}

    bool StartingPage::get_IsBusy(void) const
    {
        return isBusy;
    }

    QString StartingPage::get_signinUser(void) const
    {
        return signinUser -> text();
    }

    QString StartingPage::get_signinPwd(void) const
    {
        return signinPwd -> text();
    }

    QString StartingPage::get_signupName(void) const
    {
        return signupName -> text();
    }

    QString StartingPage::get_signupSurname(void) const
    {
        return signupSurname -> text();
    }

    QString StartingPage::get_signupUser(void) const
    {
        return signupUser -> text();
    }

    QString StartingPage::get_signupPwd(void) const
    {
        return signupPwd -> text();
    }

    void StartingPage::set_IsBusy(bool new_value)
    {
        isBusy = new_value;

        if (get_IsBusy())
        {
            signinBtn -> setEnabled(false);
            signupBtn -> setEnabled(false);
        }
        else
        {
            signinBtn -> setEnabled(true);
            signupBtn -> setEnabled(true);
        }
    }

    void StartingPage::showDialog(DialogTypes dialog_type)
    {
        set_IsBusy(true);

        switch (dialog_type)
        {
            case DialogTypes::Signin:
                signinDialog -> show();
                break;
            case DialogTypes::Signup:
                signupDialog -> show();
                break;
            case DialogTypes::SigninSuccess:
                successText -> setText("Sign-in successful");
                successDialog -> show();
                break;
            case DialogTypes::SigninFailure:
                errorText -> setText("Error in the sign-in");
                failureDialog -> show();
                break;
            case DialogTypes::SignupSuccess:
                successText -> setText("Sign-up successful");
                successDialog -> show();
                break;
            case DialogTypes::SignupFailure:
                errorText -> setText("Error in the sign-up");
                failureDialog -> show();
                break;
            default:
                throw std::exception();
        }
    }

    void StartingPage::closeDialog()
    {
        signinUser -> setText("");
        signinPwd -> setText("");
        signinOkBtn -> setEnabled(false);
        signinDialog -> close();

        signupName -> setText("");
        signupSurname -> setText("");
        signupUser -> setText("");
        signupPwd -> setText("");
        signupOkBtn -> setEnabled(false);
        signupDialog -> close();

        successDialog -> close();
        failureDialog -> close();
        set_IsBusy(false);
    }

    void Views::StartingPage::successAuth()
    {
        closeDialog();
    }

    void Views::StartingPage::errorAuth()
    {
        closeDialog();
    }

    void Views::StartingPage::validateSignin()
    {
        if (get_signinUser().length() > 3 && get_signinPwd().length() > 3)
        {
            signinOkBtn -> setEnabled(true);
        }
    }

    void Views::StartingPage::validateSignup()
    {
        if (get_signupUser().length() > 3 && get_signupPwd().length() > 3)
        {
            signupOkBtn -> setEnabled(true);
        }
    }

    void StartingPage::initSigninDialog()
    {
        QVBoxLayout* mainLayout = new QVBoxLayout{signinDialog};
        signinUser = new QLineEdit(signinDialog);
        signinPwd = new QLineEdit(signinDialog);
        signinOkBtn = new QPushButton("Sign In");
        QLabel* forgotPassword = new QLabel(signinDialog);

        signinUser -> setPlaceholderText("Username");
        signinUser -> setClearButtonEnabled(true);
        signinPwd -> setPlaceholderText("Password");
        signinPwd -> setClearButtonEnabled(true);
        signinPwd -> setEchoMode(QLineEdit::Password);
        forgotPassword -> setText("<font color='blue'><a href='#'>Forgot password?</a></font>");
        forgotPassword -> setTextFormat(Qt::AutoText);
        forgotPassword ->setAlignment(Qt::AlignCenter);
        signinOkBtn -> setEnabled(false);

        mainLayout -> addWidget(signinUser);
        mainLayout -> addWidget(signinPwd);
        mainLayout -> addWidget(signinOkBtn);
        mainLayout -> addWidget(forgotPassword);

        QObject::connect(signinUser, &QLineEdit::textChanged, this, &StartingPage::validateSignin);
        QObject::connect(signinPwd, &QLineEdit::textChanged, this, &StartingPage::validateSignin);
        QObject::connect(signinOkBtn, &QPushButton::pressed, this, &StartingPage::signinRequest);
        QObject::connect(forgotPassword, &QLabel::linkActivated, this, &StartingPage::forgotPassword);
    }

    void StartingPage::initSignupDialog()
    {
        QVBoxLayout* mainLayout = new QVBoxLayout{signupDialog};

        signupName = new QLineEdit(signupDialog);
        signupSurname = new QLineEdit(signupDialog);
        signupUser = new QLineEdit(signupDialog);
        signupPwd = new QLineEdit(signupDialog);
        signupOkBtn = new QPushButton("Sign Up");

        signupName -> setPlaceholderText("Name");
        signupName -> setClearButtonEnabled(true);
        signupSurname -> setPlaceholderText("Surname");
        signupSurname -> setClearButtonEnabled(true);
        signupUser -> setPlaceholderText("Username");
        signupUser -> setClearButtonEnabled(true);
        signupPwd -> setPlaceholderText("Password");
        signupPwd -> setClearButtonEnabled(true);
        signupPwd -> setEchoMode(QLineEdit::Password);
        signupOkBtn -> setEnabled(false);

        mainLayout -> addWidget(signupName);
        mainLayout -> addWidget(signupSurname);
        mainLayout -> addWidget(signupUser);
        mainLayout -> addWidget(signupPwd);
        mainLayout -> addWidget(signupOkBtn);

        QObject::connect(signupUser, &QLineEdit::textChanged, this, &StartingPage::validateSignup);
        QObject::connect(signupPwd, &QLineEdit::textChanged, this, &StartingPage::validateSignup);
        QObject::connect(signupOkBtn, &QPushButton::pressed, this, &StartingPage::signupRequest);
    }

    void StartingPage::initSuccessDialog()
    {
        QVBoxLayout* mainLayout = new QVBoxLayout{successDialog};

        successText = new QLabel("Login successfully");
        QPushButton* ok = new QPushButton("Ok");

        mainLayout -> addWidget(successText);
        mainLayout -> addWidget(ok);

        QObject::connect(ok, &QPushButton::pressed, this, &StartingPage::successAuth);
    }

    void StartingPage::initFailureDialog()
    {
        QVBoxLayout* mainLayout = new QVBoxLayout{failureDialog};

        errorText = new QLabel("Wrong credentials");
        QPushButton* ok = new QPushButton("Ok");

        mainLayout -> addWidget(errorText);
        mainLayout -> addWidget(ok);

        QObject::connect(ok, &QPushButton::pressed, this, &StartingPage::errorAuth);
    }
}
