#include "SignupDialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

Views::SubViews::SignupDialog::SignupDialog(QWidget *parent)
    : QDialog{parent}
{
    QVBoxLayout* mainLayout = new QVBoxLayout();

    insertName = new QLineEdit(this);
    insertSurname = new QLineEdit(this);
    insertUsername = new QLineEdit(this);
    insertPassword = new QLineEdit(this);
    QPushButton* ok = new QPushButton("Sign Up");

    insertName -> setPlaceholderText("Name");
    insertName -> setClearButtonEnabled(true);
    insertSurname -> setPlaceholderText("Surname");
    insertSurname -> setClearButtonEnabled(true);
    insertUsername -> setPlaceholderText("Username");
    insertUsername -> setClearButtonEnabled(true);
    insertPassword -> setPlaceholderText("Password");
    insertPassword -> setClearButtonEnabled(true);
    insertPassword -> setEchoMode(QLineEdit::Password);

    mainLayout -> addWidget(insertName);
    mainLayout -> addWidget(insertSurname);
    mainLayout -> addWidget(insertUsername);
    mainLayout -> addWidget(insertPassword);
    mainLayout -> addWidget(ok);
    setLayout(mainLayout);

    QObject::connect(ok, &QPushButton::pressed, this, &SignupDialog::signupRequest);
}
