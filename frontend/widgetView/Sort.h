#ifndef SORT_H
#define SORT_H

#include <QWidget>
#include <QRadioButton>

class Sort : public QWidget{
    Q_OBJECT
private :
    QRadioButton* sortIdButton;
    QRadioButton* sortDateButton;
public:
    Sort(QWidget* =nullptr);
    Q_SLOT void clickedSend();
    Q_SIGNAL void sort_id();
    Q_SIGNAL void sort_date();
};

#endif