#include "StartingPageController.h"

namespace Controllers
{

    StartingPageController::StartingPageController(Views::StartingPage *v, Models::AppService *m)
        : view(v), model(m)
    {
        QObject::connect(view, &Views::StartingPage::signinPopup,
                         this, &StartingPageController::signinPopup_clicked);
        QObject::connect(view, &Views::StartingPage::signupPopup,
                         this, &StartingPageController::signupPopup_clicked);
        QObject::connect(view, &Views::StartingPage::closedDialog, view, &Views::StartingPage::closeDialog);

        QObject::connect(view, &Views::StartingPage::signinRequest,
                         this, &StartingPageController::signin);
        QObject::connect(view, &Views::StartingPage::forgotPassword,
                         this, &StartingPageController::passwordForgotten);
        QObject::connect(view, &Views::StartingPage::signupRequest,
                         this, &StartingPageController::signup);

    }

    StartingPageController::~StartingPageController(void) {}


    void StartingPageController::signinPopup_clicked(void)
    {
        view -> showDialog(Views::DialogTypes::Signin);
    }

    void StartingPageController::signupPopup_clicked(void)
    {
        view -> showDialog(Views::DialogTypes::Signup);
    }

    void StartingPageController::signin(void)
    {
        view -> set_IsBusy_login(true);
        bool result = model -> processSignin(view -> get_signinUser(), view -> get_signinPwd());
        if (result)
        {
            view -> showDialog(Views::DialogTypes::SigninSuccess);
        }
        else
        {
            view -> showDialog(Views::DialogTypes::SigninFailure);
        }
    }

    void StartingPageController::passwordForgotten(void)
    {
        qDebug() << "pwd forgotten";
    }

    void StartingPageController::signup(void)
    {
        view -> set_IsBusy_signup(true);
        bool result = model -> processSignup(
            view -> get_signupName(), view -> get_signupSurname(), view -> get_signupEmail(),
            view -> get_signupUser(), view -> get_signupPwd());
        if (result)
        {
            view -> showDialog(Views::DialogTypes::SignupSuccess);
        }
        else
        {
            view -> showDialog(Views::DialogTypes::SignupFailure);
        }
    }

}
