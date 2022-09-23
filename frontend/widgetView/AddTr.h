#ifndef ADDTR_H
#define ADDTR_H

#include <QWidget>
#include <QVBoxLayout>
#include "../backend/controller.h"

class AddTr : public QWidget{
    Q_OBJECT
private :
    Controller* controller;
    QVBoxLayout* trainingExercisesL;
    //QList<> for exercises layout
public:
    AddTr(QWidget*, Controller*);
    Q_SLOT void clickedAddExercise();
};

#endif