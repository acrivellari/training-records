#include "StartingPage.h"

#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>

namespace Views
{
    StartingPage::StartingPage(QWidget *parent)
        : QWidget{parent}, signinDialog{new MyDialog{this}}, signupDialog{new MyDialog{this}}
    {
        initSigninDialog();
        initSignupDialog();
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
            default:
                throw std::exception();
        }
    }

    void StartingPage::closeDialog()
    {
        signinDialog -> close();
        signupDialog -> close();
        set_IsBusy(false);
    }

    void StartingPage::initSigninDialog()
    {
        QVBoxLayout* mainLayout = new QVBoxLayout{signinDialog};
        textFields_signin["insertUsername"] = new QLineEdit(signinDialog);
        textFields_signin["insertPassword"] = new QLineEdit(signinDialog);
        QPushButton* ok = new QPushButton("Sign In");
        QLabel* forgotPassword = new QLabel(signinDialog);

        textFields_signin["insertUsername"] -> setPlaceholderText("Username");
        textFields_signin["insertUsername"] -> setClearButtonEnabled(true);
        textFields_signin["insertPassword"] -> setPlaceholderText("Password");
        textFields_signin["insertPassword"] -> setClearButtonEnabled(true);
        textFields_signin["insertPassword"] -> setEchoMode(QLineEdit::Password);
        forgotPassword -> setText("<font color='blue'><a href='#'>Forgot password?</a></font>");
        forgotPassword -> setTextFormat(Qt::AutoText);
        forgotPassword ->setAlignment(Qt::AlignCenter);

        mainLayout -> addWidget(textFields_signin["insertUsername"]);
        mainLayout -> addWidget(textFields_signin["insertPassword"]);
        mainLayout -> addWidget(ok);
        mainLayout -> addWidget(forgotPassword);

        QObject::connect(ok, &QPushButton::pressed, this, &StartingPage::signinRequest);
        QObject::connect(forgotPassword, &QLabel::linkActivated, this, &StartingPage::forgotPassword);

    }

    void StartingPage::initSignupDialog()
    {
        QVBoxLayout* mainLayout = new QVBoxLayout{signupDialog};

        textFields_signup["insertName"] = new QLineEdit(signupDialog);
        textFields_signup["insertSurname"] = new QLineEdit(signupDialog);
        textFields_signup["insertUsername"] = new QLineEdit(signupDialog);
        textFields_signup["insertPassword"] = new QLineEdit(signupDialog);
        QPushButton* ok = new QPushButton("Sign Up");

        textFields_signup["insertName"] -> setPlaceholderText("Name");
        textFields_signup["insertName"] -> setClearButtonEnabled(true);
        textFields_signup["insertSurname"] -> setPlaceholderText("Surname");
        textFields_signup["insertSurname"] -> setClearButtonEnabled(true);
        textFields_signup["insertUsername"] -> setPlaceholderText("Username");
        textFields_signup["insertUsername"] -> setClearButtonEnabled(true);
        textFields_signup["insertPassword"] -> setPlaceholderText("Password");
        textFields_signup["insertPassword"] -> setClearButtonEnabled(true);
        textFields_signup["insertPassword"] -> setEchoMode(QLineEdit::Password);

        mainLayout -> addWidget(textFields_signup["insertName"]);
        mainLayout -> addWidget(textFields_signup["insertSurname"]);
        mainLayout -> addWidget(textFields_signup["insertUsername"]);
        mainLayout -> addWidget(textFields_signup["insertPassword"]);
        mainLayout -> addWidget(ok);

        QObject::connect(ok, &QPushButton::pressed, this, &StartingPage::signupRequest);
    }
}
