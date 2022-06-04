#include "../../widgetView/wvSignup.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

WV_Signup::WV_Signup(QWidget* p) : QWidget{p}{
    QVBoxLayout* layout;
    QPushButton* sendButton;
    QLineEdit* name;
    QLineEdit* surname;

    layout = new QVBoxLayout{this};
    username = new QLineEdit{this};
    password = new QLineEdit{this};
    sendButton = new QPushButton{this};
    name = new QLineEdit{this};
    surname = new QLineEdit{this};

    username -> setPlaceholderText("Insert username");
    password -> setPlaceholderText("Insert password");
    sendButton -> setText("SIGNUP");
    name -> setPlaceholderText("Insert name");
    surname -> setPlaceholderText("Insert surname");

    layout -> addWidget(name);
    layout -> addWidget(surname);
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
    return result;
}