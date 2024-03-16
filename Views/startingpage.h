#ifndef STARTINGPAGE_H
#define STARTINGPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

namespace Views::SubViews {
    class StartingPage : public QWidget
    {
        Q_OBJECT

    private:
        QPushButton * login, * signup;
        bool isBusy;

        Q_SLOT void LoginBtnClicked();
        Q_SLOT void SignupBtnClicked();

    public:
        explicit StartingPage(QWidget *parent = nullptr);
        bool getIsBusy() const;
        void setIsBusy(bool);

    signals:
        void loginPopup();
        void signupPopup();
    };
}
#endif // STARTINGPAGE_H
