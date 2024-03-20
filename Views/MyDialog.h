#ifndef AuthDialog_H
#define AuthDialog_H

#include <QDialog>

namespace Views
{
    class MyDialog : public QDialog
    {
        Q_OBJECT

    protected:
        void closeEvent(QCloseEvent *event) override;

    public:
        MyDialog(QWidget* p = nullptr);
        ~MyDialog();

    signals:
        void closedDialog(void);
    };
}

#endif
