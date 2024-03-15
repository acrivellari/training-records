#include "StartingPage.h"

#include <QMainWindow>
StartingPage::StartingPage(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* mainLayout = new QVBoxLayout();

    login = new QPushButton("LOGIN", this);
    signup = new QPushButton("SIGNUP", this);

    mainLayout -> addWidget(login);
    mainLayout -> addWidget(signup);
    setLayout(mainLayout);

    QObject::connect(login, SIGNAL(clicked(bool)), this, SIGNAL(loginPopup(bool)));
}
