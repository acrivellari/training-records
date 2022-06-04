#include "../../widgetView/wvAuth.h"

WV_Auth::WV_Auth(QWidget* p) : QWidget{p}, loginWindow{new WV_Login{this}}, signupWindow{new WV_Signup{this}} {
    loginWindow -> show();
}

