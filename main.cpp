#include "Controller/MainWindowController.h"
#include "Controller/StartingPageController.h"
#include "Views/StartingPage.h"

#include <QApplication>

class AppInitializer
{
    Controllers::StartingPageController *contr_startingPage;
    Controllers::MainWindowController *contr_main;
public:
    AppInitializer();
    ~AppInitializer();
};



int main(int argc, char *argv[])
{
    QApplication qapp(argc, argv);

    AppInitializer qapp_initialized;

    return qapp.exec();
}



AppInitializer::AppInitializer()
{
    Models::AppService *model = new Models::AppService();

    Views::StartingPage *view_startingPage = new Views::StartingPage();
    Views::MainWindow *view_main = new Views::MainWindow(view_startingPage);

    contr_startingPage = new Controllers::StartingPageController
    {
        view_startingPage,
        model
    };

    contr_main = new Controllers::MainWindowController
    {
        view_main,
        model
    };
}

AppInitializer::~AppInitializer()
{
    delete contr_startingPage;
    delete contr_main;
}
