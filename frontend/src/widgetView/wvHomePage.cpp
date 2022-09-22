#include "../../widgetView/wvHomePage.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QScrollArea>

WV_HomePage::WV_HomePage(QWidget* p) : QWidget{p} {}

void WV_HomePage::buildPage(Controller* controller) {
	QVBoxLayout * mainLayout = new QVBoxLayout{this};
	setLayout(mainLayout);
	
	//HEADER
	QScrollArea* headerArea = new QScrollArea{};
	headerArea -> setWidgetResizable(true);
	headerArea -> setFixedHeight(50);
	headerArea -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	headerArea -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	QWidget* headerWidget = new QWidget{this};
	headerArea -> setWidget(headerWidget);
	QHBoxLayout* headerLayout = new QHBoxLayout{this};
	QPushButton* userButton = new QPushButton{"Profile", this};
	headerLayout -> addWidget(userButton);
	headerLayout -> addWidget(new QLabel{"HomePage", this});
	headerWidget -> setLayout(headerLayout);

	//BODY
	QScrollArea* bodyArea = new QScrollArea{};
	bodyArea -> setWidgetResizable(true);
	bodyArea -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	QWidget* bodyWidget = new QWidget{this};
	bodyArea -> setWidget(bodyWidget);
	QVBoxLayout* bodyLayout = new QVBoxLayout{this};

	for(unsigned short i = 0; i < controller -> getTrainingRecordsSize(); i++) {
		QString label = "Training n. " + QString::number(controller -> getTraining(i) -> getID()) + "\nDone in date " + QString::fromStdString(controller -> getTraining(i) -> getDate());
		QPushButton* actualTraining = new QPushButton{label, this};
		bodyLayout -> addWidget(actualTraining);
	}

	bodyWidget -> setLayout(bodyLayout);

	//FOOTER
	QScrollArea* footerArea = new QScrollArea{};
	footerArea -> setWidgetResizable(true);
	footerArea -> setFixedHeight(50);
	footerArea -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	footerArea -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	QWidget* footerWidget = new QWidget{this};
	footerArea -> setWidget(footerWidget);
	QHBoxLayout* footerLayout = new QHBoxLayout{this};
	QPushButton* addButton = new QPushButton{"Add", this};
	QPushButton* searchButton = new QPushButton{"Filter", this};
	QPushButton* graphsButton = new QPushButton{"Graphs", this};
	footerLayout -> addWidget(addButton);
	footerLayout -> addWidget(searchButton);
	footerLayout -> addWidget(graphsButton);
	footerWidget -> setLayout(footerLayout);
	
	mainLayout -> addWidget(headerArea);
	mainLayout -> addWidget(bodyArea);
	mainLayout -> addWidget(footerArea);

	resize(400, 400);
	show();

}