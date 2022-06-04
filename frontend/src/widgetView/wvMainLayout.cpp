#include "../../widgetView/wvMainLayout.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

WV_MainLayout::WV_MainLayout(QWidget * p) : QWidget(p) {
    QHBoxLayout* layout = new QHBoxLayout{this};

    layout -> addWidget(new QLabel("ecs dee"));
    layout -> addWidget(new QPushButton());
    setLayout(layout);
}
