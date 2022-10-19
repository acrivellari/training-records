#include "../../widgetView/Sort.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

Sort::Sort(QWidget* p) : QWidget(p) {
    QVBoxLayout* mainLayout = new QVBoxLayout{this};
    sortIdButton = new QRadioButton{this};
    sortDateButton = new QRadioButton{this};
    QPushButton* sendButton = new QPushButton{this};

    sortIdButton -> setText("Sort trainings by ID (ascending order)");
    sortDateButton -> setText("Sort trainings by Date (ascending order)");
    sendButton -> setText("Sort");
    
    setLayout(mainLayout);
    mainLayout -> addWidget(sortIdButton);
    mainLayout -> addWidget(sortDateButton);
    mainLayout -> addWidget(sendButton);

    setWindowTitle("Sort Trainings");
    setWindowFlag(Qt::Window);
    setWindowModality(Qt::WindowModal);
    setFixedSize(minimumWidth(), 100);
    show();

    QObject::connect(sendButton, &QPushButton::clicked, this, &Sort::sort_request);
}


bool Sort::isChecked() const {
    return sortIdButton -> isChecked() || sortDateButton -> isChecked();
}

bool Sort::getSortType() const {
    bool result = false;
    if (sortIdButton -> isChecked()) {
        return true;
    } else if (sortDateButton -> isChecked()) {
        return false;
    }
}