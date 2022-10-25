#ifndef ADDTR_H
#define ADDTR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QList>
#include <QPair>
#include <QGroupBox>
#include <QSlider>
#include <QLCDNumber>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QResizeEvent>
#include <set>

#include "../../backend/controller.h"

class AddTr : public QWidget{
    Q_OBJECT
private:
    Controller* controller;

    QPushButton* addNewExercise;
    QPushButton* removeExercise;
    QPushButton* addTraining;

    QDateTimeEdit* dateEdit;
    QVBoxLayout* allExercisesLayout;
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
    void buildPage();

    void addItem_exerciseNameCB(QString);
    void closeEvent(QCloseEvent*);

    Q_SLOT void clickedAddExercise();
    Q_SLOT void clickedRemoveExercise();
    Q_SLOT void changedSliderValue(int);
    Q_SLOT void clickedAddTraining();
    
    Q_SIGNAL void sort();
    Q_SIGNAL void updateCBListEx();
};

#endif