#ifndef WVIEW_H
#define WVIEW_H

#include "../backend/controller.h"
#include "widgetView/wvAuth.h"
#include "widgetView/wvHomePage.h"
#include <QWidget>

class WidgetView : public QWidget{
    Q_OBJECT
private :
    Controller* controller;
    WV_HomePage* homePage;
    WV_Auth* authentication;
public :
    WidgetView(Controller*, QWidget* = nullptr);
    void showHomePage();
    Q_SLOT void sendLogin();
    Q_SLOT void sendRegister();
    Q_SLOT void sortById();
    Q_SLOT void sortByDate();
};

#endif
