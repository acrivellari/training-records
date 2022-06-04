#include "../../widgetView/wvSignup.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

WV_Signup::WV_Signup(QWidget* p) : QWidget{p}{
    QVBoxLayout* layout;
    QPushButton* sendButton;
    QLabel* labelOther;
    QLineEdit* name;
    QLineEdit* surname;

    layout = new QVBoxLayout{this};
    username = new QLineEdit{this};
    password = new QLineEdit{this};
    sendButton = new QPushButton{this};
    labelOther = new QLabel{this};
    name = new QLineEdit{this};
    surname = new QLineEdit{this};

    username -> setPlaceholderText("Insert username");
    password -> setPlaceholderText("Insert password");
    sendButton -> setText("SIGNUP");
    labelOther -> setText("<a style= text-decoration:none; href=\"http://example.com/\">Login to your account</a>");
    name -> setPlaceholderText("Insert name");
    surname -> setPlaceholderText("Insert surname");

    layout -> addWidget(name);
    layout -> addWidget(surname);
    layout -> addWidget(username);
    layout -> addWidget(password);
    layout -> addWidget(sendButton);
    layout -> addWidget(labelOther);
    setLayout(layout);

    setWindowFlag(Qt::Window);
    setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
    setWindowModality(Qt::WindowModal);
    setWindowTitle("Signup");
    resize(200,150);
}

/*
 WV_Login::WV_Login(bool signup, QWidget * p) : QWidge{p} {
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

    if (signup) {
        sendButton -> setText("SIGNUP");
        labelOther -> setText("<a style= text-decoration:none; href=\"http://example.com/\">Login to your account</a>");

        QLineEdit* name;
        QLineEdit* surname;
        name = new QLineEdit{this};
        surname = new QLineEdit{this};

        name -> setPlaceholderText("Insert name");
        surname -> setPlaceholderText("Insert surname");
        layout -> addWidget(name);
        layout -> addWidget(surname);
    }else {
        sendButton -> setText("LOGIN");
        labelOther -> setText("<a style= text-decoration:none; href=\"http://example.com/\">Create an account</a>");
    }

    layout -> addWidget(username);
    layout -> addWidget(password);
    layout -> addWidget(sendButton);
    layout -> addWidget(labelOther);
    setLayout(layout);

    setWindowFlag(Qt::Window);
    setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
    setWindowFlag(Qt::WindowCloseButtonHint, false);
    setWindowModality(Qt::WindowModal);
    setWindowTitle("Login");
    resize(200,150);

    QObject::connect(sendButton, &QPushButton::clicked, this, &WV_Login::sendLogin);
    if (signup)  QObject::connect(&labelOther, &QLabel::linkActivated, this, &WV_Login::signup2Login);
    else        QObject::connect(&labelOther, &QLabel::linkActivated, this, &WV_Login::login2Signup);
} 
 */