#ifndef INPUTIFDIALOG_H
#define INPUTIFDIALOG_H

#include <QDialog>

namespace Ui {
class InputIfDialog;
}

class InputIfDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputIfDialog(QWidget *parent = 0);
    ~InputIfDialog();

    void getInputData(std::string &name);

private:
    Ui::InputIfDialog *ui;
};

#endif // INPUTIFDIALOG_H
