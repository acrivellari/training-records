#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include "SignupDialog.h"
#include "LoginDialog.h"
#include <QDialog>
#include <QLineEdit>
#include <QStackedWidget>

namespace Views::Dialogs {


    enum StackedDialogs {
        Login,
        Signup
    };

    class MainDialog : public QDialog
    {
        Q_OBJECT

    private:
        QStackedWidget* dialogsCollection;

    protected:
        void closeEvent(QCloseEvent*) override;

    public:
        explicit MainDialog(QWidget *parent = nullptr);

        StackedDialogs getCurrentDialog() const;
        Dialogs::LoginDialog* getLoginDialog();
        Dialogs::SignupDialog* getSignupDialog();
        void ShowDialog(Views::Dialogs::StackedDialogs index);


    signals:
        void closedDialog();
    };
}
#endif // MAINDIALOG_H
