#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_createDiagramBtn_clicked()
{
    CreateDiagramWindow *cdw = new CreateDiagramWindow();
    cdw->show();
    this->destroy();
}
