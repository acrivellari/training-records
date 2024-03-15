#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Views/MainWindow.h"
#include "../Models/Model.h"
#include <QMainWindow>
#include <QPushButton>

class Controller : public QObject
{
    Q_OBJECT
private:
    int i=0;
    MainWindow* view;
    Model* model;

    QString StringToQString(std::string);
public:
    Controller(MainWindow*, Model*);
    ~Controller();

public slots:
    void Slot1();
    void Slot2();

};
#endif // MAINWINDOW_H
