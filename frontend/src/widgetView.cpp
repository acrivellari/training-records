#include "../widgetView.h"
#include <QHBoxLayout>
#include <QPushButton>

WidgetView::WidgetView(Controller * c, QWidget * p)
    : QWidget(p), controller{c}, mainLayout{new WV_MainLayout{this}}, loginWindow(new WV_Login{false, this}) {

    setWindowTitle("Training Records");
    setWindowIcon(QIcon("../github_training-records/backend/resources/icon.png"));

    QHBoxLayout* layout = new QHBoxLayout{this};
    layout -> addWidget(mainLayout);
    setLayout(layout);
    resize(400,400);
    show();

    loginWindow -> show();
    QObject::connect(loginWindow, &WV_Login::sendLogin, this, &WidgetView::sendLogin);
}

void WidgetView::sendLogin() {
    QStringList credentials = loginWindow->getCredentials();
    std::string username = credentials.at(0).toStdString();
    std::string password = credentials.at(1).toStdString();
    if (controller -> giveCredentials(username, password)) {
        loginWindow -> hide();
    }
}
