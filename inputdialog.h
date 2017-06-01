#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

namespace Ui {
class inputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = 0);
    ~InputDialog();

    void getInputData(QString &name, int &days, int &cost);

private:
    Ui::inputDialog *ui;
};

#endif // INPUTDIALOG_H
