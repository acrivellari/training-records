#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class HomePage : public QWidget
{
    Q_OBJECT
private:
    QPushButton * login, * signup;
public:
    explicit HomePage(QWidget *parent = nullptr);

    void connectSignalSlots();
    void disconnectSignalSlots();

signals:
    void loginPopup2(bool);
};

#endif // HOMEPAGE_H
