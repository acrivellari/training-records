#include "../../widgetView/AddTr.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QMessageBox>
#include <QResizeEvent>

AddTr::AddTr(QWidget* p, Controller* c) : QWidget(p), controller (c) {
    QVBoxLayout* mainLayout = new QVBoxLayout{this};
    QHBoxLayout* dateLayout = new QHBoxLayout;
    QHBoxLayout* exerciseLayout = new QHBoxLayout;
    allExercisesLayout = new QVBoxLayout;
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
    mainLayout -> setSizeConstraint(QLayout::SetFixedSize);
    clickedAddExercise();
    
    QObject::connect(addNewExercise, &QPushButton::clicked, this, &AddTr::clickedAddExercise);
    QObject::connect(removeExercise, &QPushButton::clicked, this, &AddTr::clickedRemoveExercise);

    setWindowTitle("Add Training");
    setWindowFlag(Qt::Window);
    setWindowModality(Qt::WindowModal);
    show();
}


void AddTr::clickedRemoveExercise() {
    if (groupBoxes.isEmpty() == false) {
       
        exerciseNameLabel.last() -> deleteLater();
        exerciseNameLabel.removeLast();
        exerciseNameCBox.last() -> deleteLater();
        exerciseNameCBox.removeLast();
        nsetLabel.last() -> deleteLater();
        nsetLabel.removeLast();
        nsetCBox.last() -> deleteLater();
        nsetCBox.removeLast();
        groupBoxes.last() -> layout() -> removeItem(actualExerciseLayout.last());
        allExercisesLayout -> removeWidget(groupBoxes.last());
        actualExerciseLayout.removeLast();
        groupBoxes.last() -> deleteLater();
        groupBoxes.removeLast();
   
       resize(minimumWidth(), minimumHeight());
    }
}


void AddTr::clickedAddExercise() {
    QVBoxLayout* actualExL = new QVBoxLayout;
    QHBoxLayout* exerciseNameLayout = new QHBoxLayout;
    QHBoxLayout* nsetLayout = new QHBoxLayout;
    QGroupBox* groupBox = new QGroupBox{this};  
    QComboBox* exNameCB = new QComboBox{this};
    QComboBox* nsCB = new QComboBox{this};

    groupBoxes.push_back(groupBox);
    actualExerciseLayout.push_back(actualExL);
    exerciseNameLabel.push_back(new QLabel{"Exercise name:  ", this});
    exerciseNameCBox.push_back(exNameCB);
    nsetLabel.push_back(new QLabel{"N. Set:  ", this});
    nsetCBox.push_back(nsCB);

    groupBox -> setTitle("Exercise n. " + QString::number(groupBoxes.size()-1));

    allExercisesLayout -> addWidget(groupBox);
    groupBox -> setLayout(actualExerciseLayout.last());
    actualExerciseLayout.last() -> addLayout(exerciseNameLayout);
    actualExerciseLayout.last() -> addLayout(nsetLayout);
    exerciseNameLayout -> addWidget(exerciseNameLabel.last());
    exerciseNameLayout -> addWidget(exerciseNameCBox.last());
    nsetLayout -> addWidget(nsetLabel.last());
    nsetLayout -> addWidget(nsetCBox.last());
    groupBox -> setFixedHeight(groupBox -> sizeHint().height());
}