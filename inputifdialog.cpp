#include "inputifdialog.h"
#include "ui_inputifdialog.h"

InputIfDialog::InputIfDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputIfDialog)
{
    ui->setupUi(this);
}

InputIfDialog::~InputIfDialog()
{
    delete ui;
}

void InputIfDialog::getInputData(std::string &name)
{
    name = ui->workersEdit->text().toStdString();
}
