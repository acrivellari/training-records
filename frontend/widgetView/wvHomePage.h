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
	void closeUserForm();
	void setName(std::string);
	void setSurname(std::string);
	void setUsername(std::string);
	void setPassword(std::string);
	QString getProfileName() const;
	QString getProfileSurname() const;
	QString getProfileUsername() const;
	QString getProfilePassword() const;
	void addItem_exerciseNameCB(QString);

	Q_SLOT void clickedUser();
	Q_SLOT void clickedAdd();
	Q_SLOT void clickedSort();
	Q_SLOT void clickedFilter();
	Q_SLOT void clickedGraphs();

	Q_SIGNAL void reqUpdateCredentials();
	Q_SIGNAL void updateCBListEx();
	Q_SIGNAL void sort_request();
	Q_SIGNAL void sort_requestID();
};

#endif