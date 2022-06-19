#include <iostream>
#include "frontend/dummyView.h"
#include "frontend/widgetView.h"
#include <QApplication>

/**
 * main function
 * @param argc if 1 the dir ur executing from is one folder above
 * 
 */
int main(int argc, char *argv[]) {
    /**
     * variable to the working dir, the actual dir is the dir from where the .exe is called
     */
    std::string work_dir = ".";
    if (argc == 2)  work_dir = "..";

    QApplication app{argc, argv};
    new WidgetView{new Controller{new Model(work_dir + "/backend/resources/")}};
    return QApplication::exec();
}
