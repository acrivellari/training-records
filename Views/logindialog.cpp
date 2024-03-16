#include "LoginDialog.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QCloseEvent>
#include <QLabel>

Views::Dialogs::LoginDialog::LoginDialog(QWidget *parent)
    : QDialog{parent}
{
    QVBoxLayout* mainLayout = new QVBoxLayout();

    insertUsername = new QLineEdit(this);
    insertPassword = new QLineEdit(this);
    QPushButton* ok = new QPushButton("Sign In");
    QLabel* forgotPassword = new QLabel(this);

    insertUsername -> setPlaceholderText("Username");
    insertUsername -> setClearButtonEnabled(true);
    insertPassword -> setPlaceholderText("Password");
    insertPassword -> setClearButtonEnabled(true);
    insertPassword -> setEchoMode(QLineEdit::Password);
    forgotPassword -> setText("<font color='blue'><a href='#'>Forgot password?</a></font>");
    forgotPassword -> setTextFormat(Qt::AutoText);
    forgotPassword ->setAlignment(Qt::AlignCenter);

    mainLayout -> addWidget(insertUsername);
    mainLayout -> addWidget(insertPassword);
    mainLayout -> addWidget(ok);
    mainLayout -> addWidget(forgotPassword);
    setLayout(mainLayout);

    QObject::connect(ok, &QPushButton::pressed, this, &LoginDialog::signinRequest);
    QObject::connect(forgotPassword, &QLabel::linkActivated, this, &LoginDialog::signinRequest);
}
