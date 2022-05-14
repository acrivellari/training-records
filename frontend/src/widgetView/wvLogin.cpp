#include "../../widgetView/wvLogin.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

WV_Login::WV_Login(QWidget * p) : QWidget(p) {
    QVBoxLayout* layout = new QVBoxLayout{this};

    layout -> addWidget(new QLabel("slogins"));
    layout -> addWidget(new QPushButton());

    setLayout(layout);


    setWindowFlag(Qt::Window);
    setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
    setWindowFlag(Qt::WindowCloseButtonHint, false);
    setWindowModality(Qt::WindowModal);
    resize(200,200);
}
