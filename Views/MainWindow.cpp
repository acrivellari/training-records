#include "MainWindow.h"


Views::MainWindow::MainWindow(QWidget *parent)
    :   QMainWindow(parent), mainWidget(new QStackedWidget(this)), popupDialog(new QDialog(this)), dialogs(nullptr)
{
    dialogs = new QStackedWidget(popupDialog);
    //The loginDialog is on index 0, the signupDialog on index 1
    dialogs -> addWidget(new SubViews::LoginDialog(this));
    dialogs -> addWidget(new SubViews::SignupDialog(this));

    // The view startingPage is associated with index 0, homePage with index 1
    mainWidget -> addWidget(new SubViews::StartingPage(this));
    mainWidget -> addWidget(new SubViews::HomePage(this));

    setCentralWidget(mainWidget);

    SetMainWidget(Enums::CentralWidgets::StartingPage);
}

Views::MainWindow::~MainWindow() {}


Views::SubViews::StartingPage* Views::MainWindow::getStartingPage()
{
    SubViews::StartingPage* obj = dynamic_cast<SubViews::StartingPage*>(mainWidget -> widget(Enums::CentralWidgets::StartingPage));
    if (obj == nullptr) {
        throw std::bad_cast();
    }
    return obj;
}

Views::SubViews::HomePage* Views::MainWindow::getHomePage()
{
    SubViews::HomePage* obj = dynamic_cast<SubViews::HomePage*>(mainWidget -> widget(Enums::CentralWidgets::HomePage));
    if (obj == nullptr) {
        throw std::bad_cast();
    }
    return obj;
}

Views::SubViews::LoginDialog* Views::MainWindow::getLoginDialog()
{
    SubViews::LoginDialog* obj = dynamic_cast<SubViews::LoginDialog*>(dialogs -> widget(Enums::StackedDialogs::LoginDialog));
    if (obj == nullptr) {
        throw std::bad_cast();
    }
    return obj;
}

Views::SubViews::SignupDialog* Views::MainWindow::getSignupDialog()
{
    SubViews::SignupDialog* obj = dynamic_cast<SubViews::SignupDialog*>(dialogs -> widget(Enums::StackedDialogs::SignupDialog));
    if (obj == nullptr) {
        throw std::bad_cast();
    }
    return obj;
}

void Views::MainWindow::SetMainWidget(Enums::CentralWidgets index)
{
    mainWidget -> setCurrentIndex(index);
}

void Views::MainWindow::ShowDialog(Enums::StackedDialogs index)
{
    dialogs -> setCurrentIndex(index);
    popupDialog -> show();
    popupDialog -> adjustSize();
}

void Views::MainWindow::HideDialog() {
    popupDialog -> hide();
}
