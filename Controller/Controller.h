#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Views/MainWindow.h"
#include "../Models/AppService.h"
#include <QMainWindow>
#include <QPushButton>

class Controller : public QObject
{
    Q_OBJECT

private:
    int i=0;
    Views::MainWindow* view;
    Models::AppService* model;

    QString StringToQString(std::string);

public:
    Controller(Views::MainWindow*, Models::AppService*);
    ~Controller();

public slots:
    void ShowLoginPopup();
    void ShowSignupPopup();
    void SignIn();
    void SignUp();
    void CloseDialogCorrectly();
};
#endif // MAINWINDOW_H
