#ifndef WVHOMEPAGE_H
#define WVHOMEPAGE_H

#include <QWidget>
#include <QBoxLayout>
#include "../../backend/training.h"

class WV_HomePage : public QWidget {
	Q_OBJECT
private :

	void addHistory(QBoxLayout*, const std::vector<Training*>&);
public :
	WV_HomePage(QWidget* = nullptr);
	void buildPage(const std::vector<Training*>&);
};

#endif