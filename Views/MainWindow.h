#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QDialog>
#include <QLabel>

namespace Views{

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    private:
        QStackedWidget* widgetsCollection;
        QDialog* dialog;
        QWidget* startingPage_view;

    public:
        MainWindow(QWidget* startingPage, QWidget *parent = nullptr);
        ~MainWindow();

        void setText(const std::string&);

    signals:
        void btnClicked(void);
    };
}

#endif // MainWindow_H
