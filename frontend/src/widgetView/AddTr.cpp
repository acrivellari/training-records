#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QResizeEvent>

#include <set>

#include "../../widgetView/AddTr.h"

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
    dateEdit = new QDateTimeEdit{QDate::currentDate(), this};
    QPushButton* addNewExercise = new QPushButton{this};
    QPushButton* removeExercise = new QPushButton{this};
    QPushButton* addTraining = new QPushButton{this};

    dateLabel -> setText("Date:  ");
    dateEdit -> setCalendarPopup(true);
    dateEdit -> setDisplayFormat("dd/MM/yyyy");
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
    QObject::connect(addTraining, &QPushButton::clicked, this, &AddTr::clickedAddTraining);

    setWindowTitle("Add Training");
    setWindowFlag(Qt::Window);
    setWindowModality(Qt::WindowModal);
}

void AddTr::clickedAddExercise() {
    QVBoxLayout* actualExL = new QVBoxLayout;
    QHBoxLayout* exerciseNameLayout = new QHBoxLayout;
    QHBoxLayout* nsetLayout = new QHBoxLayout;
    QHBoxLayout* actualsetsL = new QHBoxLayout;
    QGroupBox* groupBox = new QGroupBox{this};  
    QComboBox* exNameCB = new QComboBox{this};
    QSlider* nsS = new QSlider{this};
    QLCDNumber* lcd = new QLCDNumber{2, this};

    groupBoxes.push_back(groupBox);
    actualExerciseLayout.push_back(actualExL);
    actualSetsLayout.push_back(actualsetsL);
    setsLineEdits.push_back(QList<QLineEdit*>());
    exerciseNameLabel.push_back(new QLabel{"Exercise name:  ", this});
    exerciseNameCBox.push_back(exNameCB);
    nsetLabel.push_back(new QLabel{"N. Set:  ", this});
    nsetSliders.push_back(nsS);
    lcdSets.push_back(lcd);

    groupBox -> setTitle("Exercise n. " + QString::number(groupBoxes.size()-1));
    for (std::string s : controller -> getTypesExercises())
        exNameCB -> addItem(QString::fromStdString(s));
    nsS -> setOrientation(Qt::Horizontal);
    nsS -> setMinimum(0);
    nsS -> setMaximum(20);
    nsS -> setTracking(false);
    lcd -> setSegmentStyle(QLCDNumber::Flat);
    
    allExercisesLayout -> addWidget(groupBox);
    groupBox -> setLayout(actualExerciseLayout.last());
    actualExerciseLayout.last() -> addLayout(exerciseNameLayout);
    actualExerciseLayout.last() -> addLayout(nsetLayout);
    actualExerciseLayout.last() -> addLayout(actualSetsLayout.last());
    exerciseNameLayout -> addWidget(exerciseNameLabel.last());
    exerciseNameLayout -> addWidget(exerciseNameCBox.last());
    nsetLayout -> addWidget(nsetLabel.last());
    nsetLayout -> addWidget(lcdSets.last());
    nsetLayout -> addWidget(nsetSliders.last());

    QObject::connect(nsS, &QSlider::valueChanged, this, &AddTr::changedSliderValue);
}

void AddTr::clickedRemoveExercise() {
    if (groupBoxes.isEmpty() == false) {
       
        exerciseNameLabel.last() -> deleteLater();
        exerciseNameLabel.removeLast();
        exerciseNameCBox.last() -> deleteLater();
        exerciseNameCBox.removeLast();
        nsetLabel.last() -> deleteLater();
        nsetLabel.removeLast();
        lcdSets.last() -> deleteLater();
        lcdSets.removeLast();
        nsetSliders.last() -> deleteLater();
        nsetSliders.removeLast();
        for (qsizetype j = setsLineEdits.last().size()-1; j >= 0; j--) {
            setsLineEdits.last().at(j) -> deleteLater();
            setsLineEdits.last().remove(j);
        }
        setsLineEdits.removeLast();
        groupBoxes.last() -> layout() -> removeItem(actualExerciseLayout.last());
        allExercisesLayout -> removeWidget(groupBoxes.last());
        actualExerciseLayout.removeLast();
        groupBoxes.last() -> deleteLater();
        groupBoxes.removeLast();
   
        resize(minimumWidth(), minimumHeight());
    }
}

void AddTr::changedSliderValue(int newvalue) {
    for (qsizetype i = 0; i < nsetSliders.size(); i++) {
        if (nsetSliders[i] -> value() == newvalue) {
            lcdSets[i] -> display(newvalue); 
            for (qsizetype j = setsLineEdits.at(i).size()-1; j >= 0; j--) {
                setsLineEdits.at(i).at(j) -> deleteLater();
                setsLineEdits[i].remove(j);
            }
            for (int j = 0; j < newvalue; j++) {
                QLineEdit* lineEdit = new QLineEdit{this};
                setsLineEdits[i].push_back(lineEdit);
                lineEdit -> setMaxLength(4);
                lineEdit -> setFixedWidth(QFontMetrics(lineEdit -> font()).averageCharWidth()*6);
                actualSetsLayout.at(i) -> addWidget(lineEdit);
                adjustSize();
            }
            
        }
    }
}

void AddTr::clickedAddTraining() {
    QString date = dateEdit -> date().toString("yyyy-MM-dd");
    bool success = true;
    uint trainingId;
    try {
        trainingId = controller -> addEmptyTraining(date.QString::toStdString()); 
        for (qsizetype index = 0; index < groupBoxes.size(); index++) {
            if (groupBoxes.isEmpty() == false) {
                QString exerciseName = exerciseNameCBox.at(index) -> currentText();
                int numSets = lcdSets.at(index) -> intValue();
                QStringList set_n_reps;
                for (qsizetype indexSet = 0; indexSet < numSets; indexSet++) {
                    if (setsLineEdits.isEmpty() == false && setsLineEdits.at(index).isEmpty() == false) {
                        set_n_reps.push_back(setsLineEdits.at(index).at(indexSet)->text());        
                    }
                }
                std::vector<std::string> exerciseData;
                for (QString s : set_n_reps) {
                    exerciseData.push_back(s.QString::toStdString());
                }
                controller -> addExerciseTraining(trainingId, exerciseName.QString::toStdString(), exerciseData); 
                
            }
        }
    } catch(...) {
        QMessageBox::warning(this, "Error", "There was some error in the adding process of the training.\nThe training has not been added.");
        success = false;
    }
    if (success == true) {
        QMessageBox::warning(this, "Added successfully", "Training n. "+QString::number(trainingId)+" got added successfully");
        QMessageBox::warning(this, "", QString::fromStdString(controller -> printTraining(trainingId)));
        close();
        emit sort();
    }
    
}