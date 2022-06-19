#include "../../widgetView/wvMainLayout.h"

WV_MainLayout::WV_MainLayout(QWidget * p) : QWidget(p), homepage{new WV_HomePage{this}} {

    QObject::connect(homepage, &WV_HomePage::closeWindow, this, &WV_MainLayout::closeWindow);
}

void WV_MainLayout::showHome() {
    homepage -> show();
}
