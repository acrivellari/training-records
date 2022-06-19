#ifndef WVHOMEPAGE_H
#define WVHOMEPAGE_H

#include <QWidget>

class WV_HomePage : public QWidget {
	Q_OBJECT
private :
public :
	WV_HomePage(QWidget* = nullptr);
	void closeEvent(QCloseEvent*) override;

	Q_SIGNAL void closeWindow();
};

#endif