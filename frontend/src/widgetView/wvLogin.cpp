#include "../../widgetView/wvLogin.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>


WV_Login::WV_Login(QWidget * p) : QWidget{p} {
    QVBoxLayout* layout;
    QPushButton* sendButton;
    QLabel* labelOther;

    layout = new QVBoxLayout{this};
    username = new QLineEdit{this};
    password = new QLineEdit{this};
    sendButton = new QPushButton{this};
    labelOther = new QLabel{this};

    username -> setPlaceholderText("Insert username");
    password -> setPlaceholderText("Insert password");
    sendButton -> setText("LOGIN");
    labelOther -> setText("<a style= text-decoration:none; href=\"http://example.com/\">Create an account</a>");
    
    layout -> addWidget(username);
    layout -> addWidget(password);
    layout -> addWidget(sendButton);
    layout -> addWidget(labelOther);
    setLayout(layout);

    setWindowFlag(Qt::Window);
    setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
    setWindowModality(Qt::WindowModal);
    setWindowTitle("Login");
    resize(200,150);

    QObject::connect(sendButton, &QPushButton::clicked, this, &WV_Login::sendLogin);
    QObject::connect(labelOther, &QLabel::linkActivated, this, &WV_Login::showSignup);
}

QStringList WV_Login::getCredentials() const {
    QStringList result{};
    result.push_back(username -> text());
    result.push_back(password -> text());
    return result;
}
