#include "Controller.h"

QString Controller::StringToQString(std::string s)
{
    return QString::fromStdString(s);
}

Controller::Controller(MainWindow * v, Model * m) : view(v), model(m)
{
    //QObject::connect(view, SIGNAL(clicked(bool)), this, SLOT(ButtonClicked()));
    QObject::connect(view -> startingPageView, SIGNAL(loginPopup(bool)), this, SLOT(Slot1()));
    QObject::connect(view -> homePageView, SIGNAL(loginPopup2(bool)), this, SLOT(Slot2()));
}

Controller::~Controller()
{

}

void Controller::Slot1()
{
    if (i==2) {
        view -> hide();
        qDebug() << "Window hidden";
    }
    i++;
    view -> SetMainWidget_HomePage();

    qDebug() << "Main widget changed from starting page to home page";
}

void Controller::Slot2()
{
    view -> SetMainWidget_StartingPage();
    qDebug() << "Main widget changed from home page to starting page";
}
