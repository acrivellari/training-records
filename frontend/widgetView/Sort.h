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

    bool isChecked() const;
    bool getSortType() const;

    Q_SIGNAL void sort_request();
};

#endif