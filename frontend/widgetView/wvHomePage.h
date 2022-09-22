#ifndef WVHOMEPAGE_H
#define WVHOMEPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include "../../backend/training.h"
#include "../backend/controller.h"

class WV_HomePage : public QWidget {
	Q_OBJECT
public :
	WV_HomePage(QWidget* = nullptr);
	void buildPage(Controller*);
};

#endif