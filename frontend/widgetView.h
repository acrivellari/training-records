#ifndef WVIEW_H
#define WVIEW_H

#include "../backend/controller.h"
#include "widgetView/wvAuth.h"
#include "widgetView/wvMainLayout.h"
#include <QWidget>

class WidgetView : public QWidget{
private :
    Controller* controller;
    WV_MainLayout* mainLayout;
    WV_Auth* authentication;
public :
    WidgetView(Controller*, QWidget* = nullptr);
    Q_SLOT void sendLogin();
    Q_SLOT void sendRegister();
    Q_SLOT void toClose();
};

#endif
