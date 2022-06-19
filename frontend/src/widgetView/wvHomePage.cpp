#include "../../widgetView/wvHomePage.h"
#include <QPushButton>
#include <QHBoxLayout>

WV_HomePage::WV_HomePage(QWidget* p) : QWidget(p) {
	QHBoxLayout* layout = new QHBoxLayout{this};
	QPushButton* button = new QPushButton{"ciao"};
	layout -> addWidget(button);
	setLayout(layout);
	setWindowFlag(Qt::Dialog);
	resize(400, 400);
}

void WV_HomePage::closeEvent(QCloseEvent*) {
    emit closeWindow();
}