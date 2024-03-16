#include "LoginDialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCloseEvent>

Views::SubViews::LoginDialog::LoginDialog(QWidget *parent)
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
    forgotPassword -> setText("<font color='blue'>Forgot password?</font>");
    forgotPassword -> setTextFormat(Qt::AutoText);
    forgotPassword ->setAlignment(Qt::AlignCenter);

    mainLayout -> addWidget(insertUsername);
    mainLayout -> addWidget(insertPassword);
    mainLayout -> addWidget(ok);
    mainLayout -> addWidget(forgotPassword);
    setLayout(mainLayout);

    QObject::connect(ok, &QPushButton::pressed, this, &LoginDialog::signinRequest);
}
