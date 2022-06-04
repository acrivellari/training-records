#include "../widgetView.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>

WidgetView::WidgetView(Controller * c, QWidget * p)
    : QWidget{p}, controller{c}, mainLayout{new WV_MainLayout{this}}, authentication(new WV_Auth{this, controller -> getPath()}) {

    setWindowTitle("Training Records");
    setWindowIcon(QIcon(QString::fromStdString(controller -> getPath()) + "icon.png"));

    QHBoxLayout* layout = new QHBoxLayout{this};
    layout -> addWidget(mainLayout);
    setLayout(layout);
    resize(400,400);
    QObject::connect(authentication, &WV_Auth::sendLogin, this, &WidgetView::sendLogin);
    QObject::connect(authentication, &WV_Auth::sendRegister, this, &WidgetView::sendRegister);
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
        hide();
        //error login
        QMessageBox::warning(authentication,"Login Error","There are some errors with the login.");
    }
}

void WidgetView::sendRegister() {

    std::string username, password;
    authentication -> getCredentials(username, password, true);
    if (controller -> addCredentials(username, password)) {
        if (controller -> giveCredentials(username, password)){
            authentication -> hideLogin();
            authentication -> hideSignup();
            authentication -> hide();
            show();
        }else {
            //error in saving credentials
            
            QMessageBox::warning(authentication,"Register error","There are some errors with saving the credentials.");
        }
    }else {
        //error signup
         QMessageBox::warning(authentication,"Register error","There are some errors with the registration");
    }
}