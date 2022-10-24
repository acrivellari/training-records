#ifndef SORT_H
#define SORT_H

#include <QWidget>
#include <QRadioButton>
#include <QPushButton>

#include "../../backend/backendException.h"

class Sort : public QWidget{
    Q_OBJECT
private :
    QRadioButton* sortIdButton;
    QRadioButton* sortDateButton;
    QPushButton* sendButton;
public:
    Sort(QWidget* =nullptr);
    void buildPage();
    bool isChecked() const;
    bool getSortType() const;

    Q_SIGNAL void sort_request();
};

#endif