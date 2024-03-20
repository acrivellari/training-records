#ifndef STARTINGPAGECONTROLLER_H
#define STARTINGPAGECONTROLLER_H

#include <QObject>
#include "../Views/StartingPage.h"
#include "../Models/AppService.h"

namespace Controllers {
    class StartingPageController : public QObject
    {
        Q_OBJECT

    private:
        Views::StartingPage* view;
        Models::AppService* model;

    public:
        StartingPageController(Views::StartingPage*, Models::AppService*);
        ~StartingPageController(void);

    public slots:
        void signinPopup_clicked(void);
        void signupPopup_clicked(void);
        void signin(void);
        void passwordForgotten(void);
        void signup();
    };
}

#endif // STARTINGPAGECONTROLLER_H
