#include "MyDialog.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QCloseEvent>

namespace Views
{
    MyDialog::MyDialog(QWidget* p) : QDialog(p) {}

    MyDialog::~MyDialog() {}

    void MyDialog::closeEvent(QCloseEvent *event)
    {
        emit closedDialog();
        event -> accept();
    }
}
