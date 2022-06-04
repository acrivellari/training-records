#ifndef WVIEW_H
#define WVIEW_H

#include "../backend/controller.h"
#include "widgetView/wvLogin.h"
#include "widgetView/wvMainLayout.h"
#include <QWidget>

class WidgetView : public QWidget{
private :
    Controller* controller;
    WV_MainLayout* mainLayout;
    WV_Login* loginWindow;
public :
    WidgetView(Controller*, QWidget* = nullptr);
    Q_SLOT void sendLogin();
    Q_SLOT void login2Signup();
    Q_SLOT void signup2Login();

};

#endif
