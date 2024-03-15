#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), startingPageView(new StartingPage(this)), homePageView(new HomePage(this))
{
    SetMainWidget_StartingPage();
}

MainWindow::~MainWindow() {}

void MainWindow::SetMainWidget_HomePage()
{
    homePageView -> show();
    startingPageView -> hide();
}

void MainWindow::SetMainWidget_StartingPage()
{
    homePageView -> hide();
    startingPageView -> show();
}


void MainWindow::SetLabel(const QString & s)
{
    //lineEdit1 -> setText(s);
}

