#include "StartingPage.h"
#include <QMainWindow>

Views::SubViews::StartingPage::StartingPage(QWidget *parent)
    : QWidget{parent}, isBusy{false}
{
    QVBoxLayout* mainLayout = new QVBoxLayout();

    login = new QPushButton("LOGIN", this);
    signup = new QPushButton("SIGNUP", this);

    mainLayout -> addWidget(login);
    mainLayout -> addWidget(signup);
    setLayout(mainLayout);

    QObject::connect(login, &QPushButton::pressed, this, &StartingPage::LoginBtnClicked);
    QObject::connect(signup, &QPushButton::pressed, this, &StartingPage::SignupBtnClicked);
}

void Views::SubViews::StartingPage::setIsBusy(bool value) {
    isBusy = value;
    if (getIsBusy()) {
        login -> setEnabled(false);
        signup -> setEnabled(false);
    }
    else
    {
        login -> setEnabled(true);
        signup -> setEnabled(true);
    }
}

bool Views::SubViews::StartingPage::getIsBusy() const {
    return isBusy;
}

void Views::SubViews::StartingPage::LoginBtnClicked() {
    emit loginPopup();
    setIsBusy(true);
}

void Views::SubViews::StartingPage::SignupBtnClicked() {
    emit signupPopup();
    setIsBusy(true);
}
