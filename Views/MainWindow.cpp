#include "MainWindow.h"


Views::MainWindow::MainWindow(QWidget *parent)
    :   QMainWindow(parent), widgetsCollection(new QStackedWidget(this)), dialog(new Dialogs::MainDialog(this))
{
    // The view startingPage is associated with index 0, homePage with index 1
    widgetsCollection -> addWidget(new SubViews::StartingPage(this));
    widgetsCollection -> addWidget(new SubViews::HomePage(this));

    setCentralWidget(widgetsCollection);

    SetMainWidget(CentralWidgets::StartingPage);
}

Views::MainWindow::~MainWindow() {}


Views::SubViews::StartingPage* Views::MainWindow::getStartingPage()
{
    SubViews::StartingPage* obj = dynamic_cast<SubViews::StartingPage*>(widgetsCollection -> widget(CentralWidgets::StartingPage));
    if (obj == nullptr) {
        throw std::bad_cast();
    }
    return obj;
}

Views::SubViews::HomePage* Views::MainWindow::getHomePage()
{
    SubViews::HomePage* obj = dynamic_cast<SubViews::HomePage*>(widgetsCollection -> widget(CentralWidgets::HomePage));
    if (obj == nullptr) {
        throw std::bad_cast();
    }
    return obj;
}


Views::Dialogs::LoginDialog* Views::MainWindow::getLoginDialog()
{
    return dialog -> getLoginDialog();
}

Views::Dialogs::SignupDialog* Views::MainWindow::getSignupDialog()
{
    return dialog -> getSignupDialog();
}

Views::Dialogs::MainDialog* Views::MainWindow::getMainDialog()
{
    return dialog;
}

void Views::MainWindow::SetMainWidget(CentralWidgets index)
{
    widgetsCollection -> setCurrentIndex(index);
}

void Views::MainWindow::ShowDialog(Dialogs::StackedDialogs index)
{
    dialog -> ShowDialog(index);
}

void Views::MainWindow::HideDialog() {
    dialog -> hide();
}
