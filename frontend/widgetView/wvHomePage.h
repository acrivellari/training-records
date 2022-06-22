#ifndef WVHOMEPAGE_H
#define WVHOMEPAGE_H

#include <QWidget>
#include <QBoxLayout>
#include <QScrollArea>
#include <QEvent>
#include "../../backend/training.h"

class WV_HomePage : public QWidget {
	Q_OBJECT
private :
	QScrollArea* scrollArea;
	void addHistory(QBoxLayout*, const std::vector<Training*>&);
	void resizeEvent(QResizeEvent*);
public :
	Q_SLOT void resizeScrollArea();
	Q_SIGNAL void resizeSignal();
	WV_HomePage(QWidget* = nullptr);
	void buildPage(const std::vector<Training*>&);
};

#endif