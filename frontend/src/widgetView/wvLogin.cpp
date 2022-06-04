#include "../../widgetView/wvLogin.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>


WV_Login::WV_Login(QWidget * p) : QWidget{p} {
    QVBoxLayout* layout;
    QPushButton* sendButton;

    layout = new QVBoxLayout{this};
    username = new QLineEdit{this};
    password = new QLineEdit{this};
    sendButton = new QPushButton{this};

    username -> setPlaceholderText("Insert username");
    password -> setPlaceholderText("Insert password");
    sendButton -> setText("LOGIN");

    layout -> addWidget(username);
    layout -> addWidget(password);
    layout -> addWidget(sendButton);
    setLayout(layout);

    setWindowFlag(Qt::Window);
    setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
    setWindowModality(Qt::WindowModal);
    setWindowTitle("Login");
    resize(200,150);

    QObject::connect(sendButton, &QPushButton::clicked, this, &WV_Login::sendLogin);
}

QStringList WV_Login::getCredentials() const {
    QStringList result{};
    result.push_back(username -> text());
    result.push_back(password -> text());
    return result;
}
