#include "../../widgetView/wvHomePage.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QScrollArea>

WV_HomePage::WV_HomePage(QWidget* p, Controller* c) :
	 QWidget{p}, controller{c}, sortForm{new Sort{this}}, addForm{new AddTr{this, c}}, userForm{new User{this}} {
	
	QObject::connect(userForm, &User::reqUpdateCredentials, this, &WV_HomePage::reqUpdateCredentials);
	QObject::connect(addForm, &AddTr::sort, this, &WV_HomePage::sort_requestID);
	QObject::connect(sortForm, &Sort::sort_request, this, &WV_HomePage::sort_request);
}

void WV_HomePage::buildPage() {
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
	QLabel* titlePage = new QLabel{"HOMEPAGE", this};
	titlePage -> setStyleSheet("font-size:20px; margin-left:50px; font-weight: bold");
	headerLayout -> addWidget(userButton);
	headerLayout -> addWidget(titlePage);

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
		///TODO: QObject::connect(actualTraining, &QPushButton::clicked, this, &WV_HomePage::clickedTraining);

	}

	bodyWidget -> setLayout(bodyLayout);

	//FOOTER
	QScrollArea* footerArea = new QScrollArea{};
	footerArea -> setWidgetResizable(true);
	footerArea -> setFixedHeight(80);
	footerArea -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	footerArea -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	QWidget* footerWidget = new QWidget{this};
	footerArea -> setWidget(footerWidget);
	QVBoxLayout* footerLayout = new QVBoxLayout{this};
	QHBoxLayout* sortSubLayout = new QHBoxLayout{this};
	QPushButton* addButton = new QPushButton{"ADD", this};
	addButton -> setStyleSheet("font-weight: bold; font-size: 15px");
	QPushButton* filterButton = new QPushButton{"Filter", this};
	QPushButton* sortButton = new QPushButton{"Sort", this};
	QPushButton* graphsButton = new QPushButton{"Graphs", this};
	footerLayout -> addWidget(addButton);
	sortSubLayout -> addWidget(sortButton);
	sortSubLayout -> addWidget(filterButton);
	sortSubLayout -> addWidget(graphsButton);
	footerLayout -> addLayout(sortSubLayout);
	
	footerWidget -> setLayout(footerLayout);
	
	mainLayout -> addWidget(headerArea);
	mainLayout -> addWidget(bodyArea);
	mainLayout -> addWidget(footerArea);

	resize(400, 400);
	show();

	//CONNECTS
	QObject::connect(userButton, &QPushButton::clicked, this, &WV_HomePage::clickedUser);
	QObject::connect(addButton, &QPushButton::clicked, this, &WV_HomePage::clickedAdd);
	QObject::connect(sortButton, &QPushButton::clicked, this, &WV_HomePage::clickedSort);
	QObject::connect(filterButton, &QPushButton::clicked, this, &WV_HomePage::clickedFilter);
	QObject::connect(graphsButton, &QPushButton::clicked, this, &WV_HomePage::clickedGraphs);
	
	
}

void WV_HomePage::clickedUser() {
	userForm -> show();
}

void WV_HomePage::clickedAdd() {
	addForm -> show();
}

void WV_HomePage::clickedSort() {
	sortForm -> show();
}

void WV_HomePage::clickedFilter() {
	close();
}

void WV_HomePage::clickedGraphs() {
	close();
}

//have to use qsignalmapper for trainings

bool WV_HomePage::isSortChecked() const {
	bool result = false;
	if (sortForm != nullptr)
		result = sortForm -> isChecked();
	return result;
}

bool WV_HomePage::getSortType() const {
	return sortForm -> getSortType();
}

void WV_HomePage::closeSortForm() {
	if (sortForm != nullptr)
		sortForm -> close();
}

void WV_HomePage::setName(std::string name) {
	userForm -> setName(QString::fromStdString(name));
}

void WV_HomePage::setSurname(std::string surname) {
	userForm -> setSurname(QString::fromStdString(surname));
}

void WV_HomePage::setUsername(std::string username) {
	userForm -> setUsername(QString::fromStdString(username));
}

void WV_HomePage::setPassword(std::string password) {
	userForm -> setPassword(QString::fromStdString(password));
}