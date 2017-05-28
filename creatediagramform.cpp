#include "creatediagramform.h"
#include "ui_creatediagramform.h"
#include "scene.h"

#include <shapes/bar.h>
#include <shapes/block.h>
#include <shapes/entrance.h>
#include <shapes/exit.h>
#include <shapes/ifblock.h>

CreateDiagramForm::CreateDiagramForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateDiagramForm)
{
    ui->setupUi(this);
    ui->mainGraphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->mainGraphicsView->setRenderHint(QPainter::Antialiasing);

    myScene = new Scene();
    sceneCenterX = ui->mainGraphicsView->pos().x() / 2;
    sceneCenterY = ui->mainGraphicsView->pos().y() / 2;
    ui->mainGraphicsView->setScene(myScene);
}

CreateDiagramForm::~CreateDiagramForm()
{
    delete ui;
}

void CreateDiagramForm::on_blockButton_clicked()
{
    Block *block = new Block(sceneCenterX, sceneCenterY, 100, 50);
    myScene->addItem(block);
}

void CreateDiagramForm::on_ifBlockButton_clicked()
{
    IfBlock *ifBlock = new IfBlock(sceneCenterX, sceneCenterY);
    myScene->addItem(ifBlock);
}

void CreateDiagramForm::on_endBlockButton_clicked()
{
     Exit *exit = new Exit(sceneCenterX, sceneCenterY);
     myScene->addItem(exit);
}

void CreateDiagramForm::on_barButton_clicked()
{
     Bar *bar = new Bar(sceneCenterX, sceneCenterY);
     myScene->addItem(bar);
}

void CreateDiagramForm::on_startBlockButton_clicked()
{
     Entrance *entrance = new Entrance(sceneCenterX, sceneCenterY);
     myScene->addItem(entrance);
}

void CreateDiagramForm::on_clearSceneButton_clicked()
{
    myScene->clear();
}
