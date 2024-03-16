#include "Controller.h"



QString Controller::StringToQString(std::string s)
{
    return QString::fromStdString(s);
}

Controller::Controller(Views::MainWindow * v, Models::AppService * m) : view(v), model(m)
{
    using Views::SubViews::StartingPage;
    using Views::Dialogs::LoginDialog;
    using Views::Dialogs::SignupDialog;
    using Views::Dialogs::MainDialog;

    QObject::connect(view -> getStartingPage(), &StartingPage::loginPopup, this, &Controller::ShowLoginPopup);
    QObject::connect(view -> getStartingPage(), &StartingPage::signupPopup, this, &Controller::ShowSignupPopup);
    QObject::connect(view -> getLoginDialog(), &LoginDialog::signinRequest, this, &Controller::SignIn);
    QObject::connect(view -> getSignupDialog(), &SignupDialog::signupRequest, this, &Controller::SignUp);
    QObject::connect(view -> getMainDialog(), &MainDialog::closedDialog, this, &Controller::CloseDialogCorrectly);
}

Controller::~Controller()
{

}

void Controller::ShowLoginPopup() {
    if (view -> getStartingPage() -> getIsBusy() == false)
    {
        view -> ShowDialog(Views::Dialogs::StackedDialogs::Login);
    }
}

void Controller::ShowSignupPopup() {
    if (view -> getStartingPage() -> getIsBusy() == false)
    {
        view -> ShowDialog(Views::Dialogs::StackedDialogs::Signup);
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

void Controller::CloseDialogCorrectly()
{
    switch (view -> getMainDialog() -> getCurrentDialog())
    {
        case Views::Dialogs::StackedDialogs::Login:
        case Views::Dialogs::StackedDialogs::Signup:
            view -> getStartingPage() -> setIsBusy(false);
            break;
        default:
            break;
    }

    view -> HideDialog();
}
