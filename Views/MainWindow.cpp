#include "MainWindow.h"
#include <QPushButton>

#include <QVBoxLayout>

Views::MainWindow::MainWindow(QWidget* startingPage, QWidget *parent)
    :   QMainWindow(parent),
        widgetsCollection(new QStackedWidget(this)),
        dialog(new QDialog(this)),
        startingPage_view(startingPage)
{
    // The view startingPage is associated with index 0, homePage with index 1

    widgetsCollection -> addWidget(startingPage);
    //widgetsCollection -> addWidget(new SubViews::HomePage(this));

    setCentralWidget(widgetsCollection);
    widgetsCollection -> setCurrentWidget(startingPage);
    //SetMainWidget(CentralWidgets::StartingPage);

    show();
}

Views::MainWindow::~MainWindow()
{
}
