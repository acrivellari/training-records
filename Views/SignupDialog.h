#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QLineEdit>

namespace Views::SubViews {

    class SignupDialog : public QDialog
    {
        Q_OBJECT

    private:
        QLineEdit *insertUsername, *insertPassword, *insertName, *insertSurname;

    public:
        explicit SignupDialog(QWidget *parent = nullptr);

    signals:
        void signupRequest();
    };
}
#endif // SIGNUPDIALOG_H
