#include "../widgetView.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <cctype>

WidgetView::WidgetView(Controller * c, QWidget * p)
    : QWidget{p}, controller{c}, mainLayout{new WV_MainLayout{this}}, authentication(new WV_Auth{nullptr, controller -> getPath()}) {

    setWindowTitle("Training Records");
    setWindowIcon(QIcon(QString::fromStdString(controller -> getPath()) + "icon.png"));

    QHBoxLayout* layout = new QHBoxLayout{this};
    layout -> addWidget(mainLayout);
    setLayout(layout);
    resize(400,400);
    QObject::connect(authentication, &WV_Auth::sendLogin, this, &WidgetView::sendLogin);
    QObject::connect(authentication, &WV_Auth::sendRegister, this, &WidgetView::sendRegister);
    QObject::connect(authentication, &WV_Auth::closeWindow, this, &WidgetView::toClose);
    QObject::connect(mainLayout, &WV_MainLayout::closeWindow, this, &WidgetView::toClose);
}

void WidgetView::sendLogin() {
    std::string username, password;
    authentication -> getCredentialsLogin(username, password);
    if (controller -> giveCredentials(username, password)) {
        authentication -> hideLogin();
        authentication -> hideSignup();
        authentication -> hide();
        mainLayout -> showHome();
    }else {
        QMessageBox::warning(authentication, "Login Error", "The combination of username and password you provided doesn't exist in our database");
    }
}

void WidgetView::sendRegister() {
    std::string username, password, name, surname;
    authentication -> getCredentialsSignup(username, password, name, surname);
    if (name.empty() == false) {
        for (std::string::iterator it = name.begin(); it != name.end(); it++) {
            if (isalpha(*it) == false) {
                name.erase(it);
                it--;
            }
        }
    }
    if (surname.empty() == false) {
        for (std::string::iterator it = surname.begin(); it != surname.end(); it++) {
            if (isalpha(*it) == false) {
                surname.erase(it);
                it--;
            }
        }
    }
    if (username.size() >= 6 && password.size() >= 6 && controller -> addCredentials(username, password, name, surname)) {
        authentication -> hideLogin();
        authentication -> hideSignup();
        authentication -> hide();
        mainLayout -> showHome();
    }else {
        if (username.size() >= 6 && password.size() >= 6) {
            QMessageBox::warning(authentication, "Register error", "This user already exists in our database.");
        }else if (username.size() <= 6 && password.size() <= 6) {
            QMessageBox::warning(authentication, "Register error", "Both the username and the password you chose are too short.");
        }else if (username.size() <= 6) {
            QMessageBox::warning(authentication, "Register error", "The username you chose is too short");
        }else if (password.size() <= 6) {
            QMessageBox::warning(authentication, "Register error", "The password you chose is too short");
        }
    }
}

void WidgetView::toClose() {
    mainLayout -> close();
    authentication -> close();
    close();
    delete mainLayout;
    delete authentication;
    delete this;
}