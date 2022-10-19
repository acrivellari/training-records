#ifndef WVHOMEPAGE_H
#define WVHOMEPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include "../../backend/training.h"
#include "../../backend/controller.h"

class WV_HomePage : public QWidget {
	Q_OBJECT
private:
	Controller * controller;
public :
	WV_HomePage(QWidget*, Controller*);
	void buildPage();

	Q_SLOT void clickedUser();
	Q_SLOT void clickedAdd();
	Q_SLOT void clickedSort();
	Q_SLOT void clickedFilter();
	Q_SLOT void clickedGraphs();

	Q_SIGNAL void sort_id();
	Q_SIGNAL void sort_date();
};

#endif