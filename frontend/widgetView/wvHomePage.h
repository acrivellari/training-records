#ifndef WVHOMEPAGE_H
#define WVHOMEPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include "../../backend/training.h"
#include "../../backend/controller.h"
#include "Sort.h"
#include "User.h"
#include "AddTr.h"

class WV_HomePage : public QWidget {
	Q_OBJECT
private:
	Controller * controller;
	Sort* sortForm;
	AddTr* addForm;
	User* userForm;
public :
	WV_HomePage(QWidget*, Controller*);
	void buildPage();

	bool isSortChecked() const;
	bool getSortType() const;
	void closeSortForm();

	Q_SLOT void clickedUser();
	Q_SLOT void clickedAdd();
	Q_SLOT void clickedSort();
	Q_SLOT void clickedFilter();
	Q_SLOT void clickedGraphs();

	Q_SIGNAL void sort_request();
	Q_SIGNAL void sort_requestID();
};

#endif