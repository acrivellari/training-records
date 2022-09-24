#include "../../widgetView/AddTr.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QMessageBox>
#include <QResizeEvent>

AddTr::AddTr(QWidget* p, Controller* c) : QWidget(p), controller (c) {
    QVBoxLayout* mainLayout = new QVBoxLayout{this};
    QHBoxLayout* dateLayout = new QHBoxLayout{this};
    QHBoxLayout* exerciseLayout = new QHBoxLayout{this};
    allExercisesLayout = new QVBoxLayout{this};
    QLabel* dateLabel = new QLabel{this};
    QDateTimeEdit* dateEdit = new QDateTimeEdit{QDate::currentDate(), this};
    QPushButton* addNewExercise = new QPushButton{this};
    QPushButton* removeExercise = new QPushButton{this};
    QPushButton* addTraining = new QPushButton{this};

    dateLabel -> setText("Date:  ");
    dateEdit -> setCalendarPopup(true);
    dateEdit -> setDisplayFormat("dd/mm/yyyy");
    addNewExercise -> setText("Add new exercise");
    removeExercise -> setText("Remove last exercise");
    addTraining -> setText("ADD TRAINING");

    setLayout(mainLayout);
    dateLayout -> addWidget(dateLabel);
    dateLayout -> addWidget(dateEdit);
    mainLayout -> addLayout(dateLayout);
    mainLayout -> addLayout(allExercisesLayout);
    exerciseLayout -> addWidget(addNewExercise);
    exerciseLayout -> addWidget(removeExercise);
    mainLayout -> addLayout(exerciseLayout);
    mainLayout -> addWidget(addTraining);
    clickedAddExercise();
    QObject::connect(addNewExercise, &QPushButton::clicked, this, &AddTr::clickedAddExercise);
    QObject::connect(removeExercise, &QPushButton::clicked, this, &AddTr::clickedRemoveExercise);

    setWindowTitle("Add Training");
    setWindowFlag(Qt::Window);
    setWindowModality(Qt::WindowModal);
    show();
}

void AddTr::clickedAddExercise() {
    actualExerciseLayout.push_back(new QVBoxLayout{this});
    QHBoxLayout* exerciseNameLayout = new QHBoxLayout{this};
    QHBoxLayout* nsetLayout = new QHBoxLayout{this};

    exerciseNameLabel.push_back(new QLabel{"Exercise name:  ", this});
    exerciseNameCBox.push_back(new QComboBox{this});

    allExercisesLayout -> addLayout(actualExerciseLayout.last());
    actualExerciseLayout.last() -> addLayout(exerciseNameLayout);
    exerciseNameLayout -> addWidget(exerciseNameLabel.at(exerciseNameLabel.size()-1));
    exerciseNameLayout -> addWidget(exerciseNameCBox.at(exerciseNameCBox.size()-1));
}

void AddTr::clickedRemoveExercise() {
    if (exerciseNameLabel.isEmpty())  return;
   // exerciseNameCBox.
    exerciseNameLabel.last() -> deleteLater();
    exerciseNameLabel.removeLast();
    exerciseNameCBox.last() -> deleteLater();
    exerciseNameCBox.removeLast();
    
    allExercisesLayout -> removeItem(actualExerciseLayout.last());
    actualExerciseLayout.removeLast();
    adjustSize();
}