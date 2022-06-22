#ifndef WVHOMEPAGE_H
#define WVHOMEPAGE_H

#include <QWidget>
#include <QBoxLayout>

class WV_HomePage : public QWidget {
	Q_OBJECT
private :
	void addHistory(QBoxLayout*);
public :
	WV_HomePage(QWidget* = nullptr);
	void buildPage();
};

#endif