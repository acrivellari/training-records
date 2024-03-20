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
        qDebug() << "signin";
    }

    void StartingPageController::passwordForgotten(void)
    {
        qDebug() << "pwd forgotten";
    }

    void StartingPageController::signup(void)
    {
        qDebug() << "signup";
    }

}
