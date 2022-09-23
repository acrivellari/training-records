#include "../../widgetView/AddTr.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDateTimeEdit>

AddTr::AddTr(QWidget* p, Controller* c) : QWidget(p), controller (c) {
    QVBoxLayout* mainLayout = new QVBoxLayout{this};
    QHBoxLayout* dateLayout = new QHBoxLayout{this};
    QHBoxLayout* exerciseLayout = new QHBoxLayout{this};
    trainingExercisesL = new QVBoxLayout{this};
    QLabel* dateLabel = new QLabel{this};
    QDateTimeEdit* dateEdit = new QDateTimeEdit{QDate::currentDate(), this};
    QPushButton* addNewExercise = new QPushButton{this};
    QPushButton* removeExercise = new QPushButton{this};
    QPushButton* addTraining = new QPushButton{this};

    dateEdit -> setCalendarPopup(true);
    dateEdit -> setDisplayFormat("dd/mm/yyyy");

    setLayout(mainLayout);
    dateLayout -> addWidget(dateLabel);
    dateLayout -> addWidget(dateEdit);
    mainLayout -> addLayout(dateLayout);
    mainLayout -> addLayout(trainingExercisesL);
    exerciseLayout -> addWidget(addNewExercise);
    exerciseLayout -> addWidget(removeExercise);
    mainLayout -> addLayout(exerciseLayout);
    mainLayout -> addWidget(addTraining);
    QObject::connect(addNewExercise, &QPushButton::clicked, this, &AddTr::clickedAddExercise);

    setWindowTitle("Add Training");
    setWindowFlag(Qt::Window);
    setWindowModality(Qt::WindowModal);
    show();
}

void AddTr::clickedAddExercise() {
    trainingExercisesL -> addWidget(new QPushButton{this});
}