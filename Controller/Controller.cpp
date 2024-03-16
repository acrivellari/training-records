#include "Controller.h"



QString Controller::StringToQString(std::string s)
{
    return QString::fromStdString(s);
}

Controller::Controller(Views::MainWindow * v, Models::AppService * m) : view(v), model(m)
{
    using Views::SubViews::StartingPage;
    using Views::SubViews::LoginDialog;
    using Views::SubViews::SignupDialog;

    QObject::connect(view -> getStartingPage(), &StartingPage::loginPopup, this, &Controller::ShowLoginPopup);
    QObject::connect(view -> getStartingPage(), &StartingPage::signupPopup, this, &Controller::ShowSignupPopup);
    QObject::connect(view -> getLoginDialog(), &LoginDialog::signinRequest, this, &Controller::SignIn);
    QObject::connect(view -> getSignupDialog(), &SignupDialog::signupRequest, this, &Controller::SignUp);
}

Controller::~Controller()
{

}

void Controller::ShowLoginPopup() {
    if (view -> getStartingPage() -> getIsBusy() == false)
    {
        view -> ShowDialog(Views::Enums::StackedDialogs::LoginDialog);
    }
}

void Controller::ShowSignupPopup() {
    if (view -> getStartingPage() -> getIsBusy() == false)
    {
        view -> ShowDialog(Views::Enums::StackedDialogs::SignupDialog);
    }
}

void Controller::SignIn()
{
    view -> getStartingPage() -> setIsBusy(false);
    view -> HideDialog();
}

void Controller::SignUp()
{
    view -> getStartingPage() -> setIsBusy(false);
    view -> HideDialog();
}
