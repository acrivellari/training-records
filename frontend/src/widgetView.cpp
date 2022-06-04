#include "../widgetView.h"
#include <QHBoxLayout>
#include <QPushButton>

WidgetView::WidgetView(Controller * c, QWidget * p)
    : QWidget{p}, controller{c}, mainLayout{new WV_MainLayout{this}}, authentication(new WV_Auth{this}) {

    setWindowTitle("Training Records");
    setWindowIcon(QIcon("../github_training-records/backend/resources/icon.png"));

    QHBoxLayout* layout = new QHBoxLayout{this};
    layout -> addWidget(mainLayout);
    setLayout(layout);
    resize(400,400);
    show();
    
    QObject::connect(authentication, &WV_Auth::sendLogin, this, &WidgetView::sendLogin);
}

void WidgetView::sendLogin() {
    std::string username, password;
    authentication -> getCredentials(username, password);
    if (controller -> giveCredentials(username, password)) {
        authentication -> hideLogin();
    }
}
