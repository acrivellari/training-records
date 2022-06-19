#ifndef WVMAINLAYOUT_H
#define WVMAINLAYOUT_H

#include <QWidget>
#include "wvHomePage.h"

class WV_MainLayout : public QWidget {
    Q_OBJECT
private :
    WV_HomePage* homepage;
    
public :
    WV_MainLayout(QWidget* = nullptr);
    void showHome();

    Q_SIGNAL void closeWindow();
};

#endif
