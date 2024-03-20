#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include "../Views/MainWindow.h"
#include "../Models/AppService.h"
#include <QMainWindow>
#include <QPushButton>

namespace Controllers {
    class MainWindowController : public QObject
    {
        Q_OBJECT

    private:
        Views::MainWindow* view;
        Models::AppService* model;

    public:
        MainWindowController(Views::MainWindow*, Models::AppService*);
        ~MainWindowController(void);


    };
}
#endif // MAINWINDOWCONTROLLER_H
