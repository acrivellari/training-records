#include "../../widgetView/wvSignup.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>


WV_Signup::WV_Signup(QWidget* p) : QWidget{p}{
    QVBoxLayout* layout;
    QPushButton* sendButton;
    QLabel* emptySpacing;

    layout = new QVBoxLayout{this};
    username = new QLineEdit{this};
    password = new QLineEdit{this};
    sendButton = new QPushButton{this};
    name = new QLineEdit{this};
    surname = new QLineEdit{this};
    emptySpacing = new QLabel{this};

    sendButton -> setText("SIGNUP");
    name -> setPlaceholderText("Insert name");
    surname -> setPlaceholderText("Insert surname");
    username -> setPlaceholderText("Insert username");
    password -> setPlaceholderText("Insert password");
    password -> setEchoMode(QLineEdit::Password);

    layout -> addWidget(name);
    layout -> addWidget(surname);
    layout -> addWidget(emptySpacing);
    layout -> addWidget(username);
    layout -> addWidget(password);
    layout -> addWidget(sendButton);
    setLayout(layout);

    setWindowFlag(Qt::Window);
    setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
    setWindowModality(Qt::WindowModal);
    setWindowTitle("Signup");
    resize(200,150);

    QObject::connect(sendButton, &QPushButton::clicked, this, &WV_Signup::sendRegister);
}

QStringList WV_Signup::getCredentials() const {
    QStringList result{};
    result.push_back(username -> text());
    result.push_back(password -> text());
    result.push_back(name -> text());
    result.push_back(surname -> text());
    return result;
}