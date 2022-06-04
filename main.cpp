#include <iostream>
#include "frontend/dummyView.h"
#include "frontend/widgetView.h"
#include <QApplication>
namespace main_testing{
    void tryOne(View* v, unsigned int value) {
        if (value == 0) return;
        DummyView* vv = dynamic_cast<DummyView*>(v);
        vv ->giveCredentials("evilcrive", "evilcrive");
        vv->load();
        vv->addEmptyTraining("2050-10-12");
        vv->modifyTraining(1, "exercise:name:pullup", "ciaoo");
        vv->modifyTraining(1, "exercise:data:ciaoo", "2-2");
        vv->save("ciao");
    }
}

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};

    /**
     * variable to the working dir, the actual dir is the dir from where the .exe is called
     */
    std::string work_dir;
    work_dir = ".";
    //work_dir = "..";
    new WidgetView{new Controller{new Model(work_dir + "/backend/resources/")}};
    return QApplication::exec();
}
