#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLineEdit>

namespace Views::SubViews {

    class LoginDialog : public QDialog
    {
        Q_OBJECT

    private:
        QLineEdit *insertUsername, *insertPassword;

    public:
        explicit LoginDialog(QWidget *parent = nullptr);

    signals:
        void signinRequest();
    };
}
#endif // LOGINDIALOG_H
