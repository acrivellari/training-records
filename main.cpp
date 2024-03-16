#include "Controller/Controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Views::MainWindow v;
    Models::AppService m;
    Controller c(&v, &m);
    v.show();
    return a.exec();
}
