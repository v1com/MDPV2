#include "creatediagramform.h"
#include "ui_creatediagramform.h"
#include "scene.h"

CreateDiagramForm::CreateDiagramForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateDiagramForm)
{
    ui->setupUi(this);
    Scene *scene = new Scene();
    ui->mainGraphicsView->setScene(scene);
}

CreateDiagramForm::~CreateDiagramForm()
{
    delete ui;
}
