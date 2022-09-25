#ifndef ADDTR_H
#define ADDTR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QList>
#include <QPair>
#include <QGroupBox>
#include <QSlider>
#include <QLCDNumber>
#include <QLineEdit>
#include <QDateTimeEdit>

#include "../backend/controller.h"

class AddTr : public QWidget{
    Q_OBJECT
private:
    Controller* controller;

    QDateTimeEdit* dateEdit;
    QVBoxLayout* allExercisesLayout;
    QList<QPair<int,int>> gbSize;
    QList<QGroupBox*> groupBoxes;
    QList<QVBoxLayout*> actualExerciseLayout;
    QList<QHBoxLayout*> actualSetsLayout;
    QList<QLabel*> exerciseNameLabel;
    QList<QLabel*> nsetLabel;
    QList<QComboBox*> exerciseNameCBox;
    QList<QSlider*> nsetSliders;
    QList<QLCDNumber*> lcdSets;
    QList<QList<QLineEdit*>> setsLineEdits;

public:
    AddTr(QWidget*, Controller*);
    Q_SLOT void clickedAddExercise();
    Q_SLOT void clickedRemoveExercise();
    Q_SLOT void changedSliderValue(int);
    Q_SLOT void clickedAddTraining();
    Q_SIGNAL void sort();
};

#endif