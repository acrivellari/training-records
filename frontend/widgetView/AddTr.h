#ifndef ADDTR_H
#define ADDTR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QList>
#include <QPair>
#include <QGroupBox>
#include "../backend/controller.h"

class AddTr : public QWidget{
    Q_OBJECT
private:
    Controller* controller;

    QVBoxLayout* allExercisesLayout;
    QList<QPair<int,int>> gbSize;
    QList<QGroupBox*> groupBoxes;
    QList<QVBoxLayout*> actualExerciseLayout;
    QList<QLabel*> exerciseNameLabel;
    QList<QLabel*> nsetLabel;
    QList<QComboBox*> exerciseNameCBox;
    QList<QComboBox*> nsetCBox;

public:
    AddTr(QWidget*, Controller*);
    Q_SLOT void clickedAddExercise();
    Q_SLOT void clickedRemoveExercise();
};

#endif