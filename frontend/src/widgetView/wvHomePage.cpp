#include "../../widgetView/wvHomePage.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

WV_HomePage::WV_HomePage(QWidget* p) : QWidget{p} {
	QVBoxLayout* mainLayout = new QVBoxLayout{this};
	QHBoxLayout* menuBarLayout = new QHBoxLayout{this};
	QPushButton* userButton = new QPushButton{"User"};
	QLabel* iconLabel = new QLabel{"xd"};
	QHBoxLayout* layout = new QHBoxLayout{this};
	QPushButton* button = new QPushButton{"ciao"};
	layout -> addWidget(button);
	setLayout(layout);
	resize(400,400);
	hide();
}
