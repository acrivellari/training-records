#include "Controller/Controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow v;
    Model m;
    Controller c(&v, &m);
    v.show();
    return a.exec();
}
