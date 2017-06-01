#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputDialog)
{
    ui->setupUi(this);
}

InputDialog::~InputDialog()
{
    delete ui;
}

void InputDialog::getInputData(std::string &name, int &days, int &cost)
{
    name = ui->nameEdit->text().toStdString();
    days = ui->daysEdit->text().toInt();
    cost = ui->costEdit->text().toInt();
}
