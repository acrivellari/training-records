#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QDialog>
#include "StartingPage.h"
#include "HomePage.h"
#include "LoginDialog.h"
#include "SignupDialog.h"

namespace Views{

    namespace Enums {
        enum CentralWidgets {
            StartingPage,
            HomePage
        };

        enum StackedDialogs {
            LoginDialog,
            SignupDialog
        };
    }

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    private:
        QStackedWidget* dialogs;
        QStackedWidget* mainWidget;
        QDialog* popupDialog;

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        void init();

        SubViews::StartingPage* getStartingPage();
        SubViews::HomePage* getHomePage();
        SubViews::LoginDialog* getLoginDialog();
        SubViews::SignupDialog* getSignupDialog();
        void SetMainWidget(Enums::CentralWidgets);

        void ShowDialog(Enums::StackedDialogs);
        void HideDialog();
    };
}

#endif // MainWindow_H
