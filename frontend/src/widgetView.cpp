#include "../widgetView.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>

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
    QObject::connect(authentication, &WV_Auth::closeWindow, this, &WidgetView::authClosed);
}

void WidgetView::sendLogin() {
    std::string username, password;
    authentication -> getCredentials(username, password, false);
    if (controller -> giveCredentials(username, password)) {
        authentication -> hideLogin();
        authentication -> hideSignup();
        authentication -> hide();
        show();
    }else {
        QMessageBox::warning(authentication, "Login Error", "The combination of username and password you provided doesn't exist in our database");
    }
}

void WidgetView::sendRegister() {
    std::string username, password;
    authentication -> getCredentials(username, password, true);
    if (username.size() >= 6 && password.size() >= 6 && controller -> addCredentials(username, password)) {
        if (controller -> giveCredentials(username, password)){
            authentication -> hideLogin();
            authentication -> hideSignup();
            authentication -> hide();
            show();
        }else {
            QMessageBox::warning(authentication, "Register error", "There are some errors with loading the credentials.");
        }
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

void WidgetView::authClosed() {
    if (isHidden())    close();
}