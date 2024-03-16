#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QDialog>
#include "StartingPage.h"
#include "HomePage.h"
#include "LoginDialog.h"
#include "SignupDialog.h"
#include "MainDialog.h"

namespace Views{


    enum CentralWidgets {
        StartingPage,
        HomePage
    };

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    private:
        QStackedWidget* widgetsCollection;
        Dialogs::MainDialog* dialog;

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        SubViews::StartingPage* getStartingPage();
        SubViews::HomePage* getHomePage();
        Dialogs::LoginDialog* getLoginDialog();
        Dialogs::SignupDialog* getSignupDialog();
        Dialogs::MainDialog* getMainDialog();
        void SetMainWidget(CentralWidgets);

        void ShowDialog(Dialogs::StackedDialogs);
        void HideDialog();
    };
}

#endif // MainWindow_H
