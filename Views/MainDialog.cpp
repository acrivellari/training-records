#include "MainDialog.h"

Views::Dialogs::MainDialog::MainDialog(QWidget *parent)
    : QDialog{parent}, dialogsCollection(new QStackedWidget(this))
{
    //The loginDialog is on index 0, the signupDialog on index 1
    dialogsCollection -> addWidget(new Dialogs::LoginDialog(this));
    dialogsCollection -> addWidget(new Dialogs::SignupDialog(this));
}

void Views::Dialogs::MainDialog::closeEvent(QCloseEvent* event) {
    emit closedDialog();
}

Views::Dialogs::StackedDialogs Views::Dialogs::MainDialog::getCurrentDialog() const
{
    return StackedDialogs(dialogsCollection -> currentIndex());
}

Views::Dialogs::LoginDialog* Views::Dialogs::MainDialog::getLoginDialog()
{
    Dialogs::LoginDialog* obj = dynamic_cast<Dialogs::LoginDialog*>(dialogsCollection -> widget(Dialogs::StackedDialogs::Login));
    if (obj == nullptr) {
        throw std::bad_cast();
    }
    return obj;
}

Views::Dialogs::SignupDialog* Views::Dialogs::MainDialog::getSignupDialog()
{
    Dialogs::SignupDialog* obj = dynamic_cast<Dialogs::SignupDialog*>(dialogsCollection -> widget(Dialogs::StackedDialogs::Signup));
    if (obj == nullptr) {
        throw std::bad_cast();
    }
    return obj;
}

void Views::Dialogs::MainDialog::ShowDialog(StackedDialogs index)
{
    dialogsCollection -> setCurrentIndex(index);
    show();
    adjustSize();
}
