#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include "StartingPage.h"
#include "HomePage.h"

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QDialog* popupDialog;

public:
    StartingPage* startingPageView;
    HomePage* homePageView;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void SetMainWidget_StartingPage();
    void SetMainWidget_HomePage();
    void SetLabel(const QString&);
};

#endif // MainWindow_H
