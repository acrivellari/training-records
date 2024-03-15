#ifndef STARTINGPAGE_H
#define STARTINGPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class StartingPage : public QWidget
{
    Q_OBJECT
private:
    QPushButton * login, * signup;
public:
    explicit StartingPage(QWidget *parent = nullptr);

signals:
    void loginPopup(bool);
};

#endif // STARTINGPAGE_H
