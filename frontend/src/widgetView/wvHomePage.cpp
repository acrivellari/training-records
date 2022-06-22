#include "../../widgetView/wvHomePage.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

WV_HomePage::WV_HomePage(QWidget* p) : QWidget{p} {}

void WV_HomePage::buildPage() {
	QVBoxLayout* mainLayout = new QVBoxLayout{this};
	QHBoxLayout* menuBarLayout = new QHBoxLayout{this};
	QVBoxLayout* historyLayout = new QVBoxLayout{this};
	QHBoxLayout* footerLayout = new QHBoxLayout{this};

	QPushButton* userButton = new QPushButton{"User"};
	QLabel* iconLabel = new QLabel{"_xdimage_xdimage_xdimage_"};
	QPushButton* addButton = new QPushButton{"Add"};
	QPushButton* searchButton = new QPushButton{"Search"};
	QPushButton* graphsButton = new QPushButton{"Graphs"};
	
	addHistory(historyLayout);

	menuBarLayout -> addWidget(userButton);
	menuBarLayout -> addWidget(iconLabel);
	footerLayout -> addWidget(addButton);
	footerLayout -> addWidget(searchButton);
	footerLayout -> addWidget(graphsButton);

	mainLayout -> addLayout(menuBarLayout);
	mainLayout -> addLayout(historyLayout);
	mainLayout -> addLayout(footerLayout);
	setLayout(mainLayout);

	resize(400,400);
	hide();
}

void WV_HomePage::addHistory(QBoxLayout* historyLayout) {
	QPushButton* uno = new QPushButton{"s"};
	historyLayout -> addWidget(uno);	
}