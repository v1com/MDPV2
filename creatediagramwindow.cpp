#include "creatediagramwindow.h"
#include "ui_creatediagramwindow.h"

CreateDiagramWindow::CreateDiagramWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateDiagramWindow)
{
    ui->setupUi(this);
}

CreateDiagramWindow::~CreateDiagramWindow()
{
    delete ui;
}
