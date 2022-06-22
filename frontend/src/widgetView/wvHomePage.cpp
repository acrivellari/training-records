#include "../../widgetView/wvHomePage.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QBoxLayout>
#include <QMessageBox>


WV_HomePage::WV_HomePage(QWidget* p) : QWidget{p} {}

void WV_HomePage::buildPage(const std::vector<Training*>& array) {
	scrollArea = new QScrollArea{parentWidget()};
	//scrollArea -> setBackgroundRole(QPalette::Dark);
	scrollArea -> show();
	QVBoxLayout* mainLayout = new QVBoxLayout{this};
	QHBoxLayout* menuBarLayout = new QHBoxLayout{this};
	QVBoxLayout* historyLayout = new QVBoxLayout{this};
	QHBoxLayout* footerLayout = new QHBoxLayout{this};

	QPushButton* userButton = new QPushButton{"User"};
	QLabel* iconLabel = new QLabel{"_xdimage_xdimage_xdimage_"};
	QPushButton* addButton = new QPushButton{"Add"};
	QPushButton* searchButton = new QPushButton{"Search"};
	QPushButton* graphsButton = new QPushButton{"Graphs"};
	
	addHistory(historyLayout, array);

	menuBarLayout -> addWidget(userButton);
	menuBarLayout -> addWidget(iconLabel);
	footerLayout -> addWidget(addButton);
	footerLayout -> addWidget(searchButton);
	footerLayout -> addWidget(graphsButton);

	mainLayout -> addLayout(menuBarLayout);
	mainLayout -> addLayout(historyLayout, 20);
	mainLayout -> addLayout(footerLayout);
	
	//setLayout(mainLayout);

	scrollArea -> setWidget(this);
	resize(400, 400);
	scrollArea -> resize(size());
	scrollArea -> setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
	//scrollArea -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//scrollArea -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	QObject::connect(this, &WV_HomePage::resizeSignal, this, &WV_HomePage::resizeScrollArea);

}

void WV_HomePage::addHistory(QBoxLayout* historyLayout, const std::vector<Training*>& array) {
	for(unsigned short i = 0; i < 30; i++) {
		QHBoxLayout* actualTraining = new QHBoxLayout{this};
		QLabel* id = new QLabel{QString::number(array[i] -> getID())};
		QLabel* date = new QLabel{QString::fromStdString(array[i] -> getDate())};
		QPushButton* modify = new QPushButton{"Modify"};
		QPushButton* remove = new QPushButton{"Remove"};
		id -> setMinimumSize(20,20);
		date -> setMinimumSize(40, 40);
		date -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		actualTraining -> addWidget(id, 2);
		actualTraining -> addWidget(date, 2);
		actualTraining -> addWidget(modify, 2);
		actualTraining -> addWidget(remove, 2);
		historyLayout -> addLayout(actualTraining, 2);
		historyLayout -> addSpacing(20);
	}
	unsigned int size = array[145]->getID();
	QPushButton* uno = new QPushButton{QString::number(size)};
	historyLayout -> addWidget(uno);	
	historyLayout -> setSizeConstraint(QLayout::SetMinAndMaxSize);
}

void WV_HomePage::resizeEvent(QResizeEvent* e) {
	emit resizeSignal();
}
void WV_HomePage::resizeScrollArea() {
	scrollArea -> resize(size());
}