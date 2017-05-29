#include "creatediagramform.h"
#include "ui_creatediagramform.h"
#include "scene.h"

#include <shapes/bar.h>
#include <shapes/block.h>
#include <shapes/entrance.h>
#include <shapes/exit.h>
#include <shapes/ifblock.h>

#include <shapes/shape.h>
#include <diagram.h>
#include <shapes/arrow.h>

using namespace  std;

CreateDiagramForm::CreateDiagramForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateDiagramForm)
{
    ui->setupUi(this);
    ui->mainGraphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->mainGraphicsView->setRenderHint(QPainter::Antialiasing);

    myScene = new Scene();
    myScene->setSceneRect(ui->mainGraphicsView->pos().x(), ui->mainGraphicsView->pos().y(), ui->mainGraphicsView->width(), ui->mainGraphicsView->height());
    sceneCenterX = myScene->width() / 2;
    sceneCenterY = myScene->height() / 2;

    shapeContainer = new Diagram<Shape>; //= new Diagram<Shape>;

    //shapeContainer->addElement(block2);
    //shapeContainer->addLink(block1, block2);

    vector<list<Shape*>> v =  shapeContainer->getVector();
        for (int i = 0; i < v.size(); i++){
            list<Shape*>::iterator Iter = v[i].begin();
            list<Shape*>::iterator endIter = v[i].end();
            myScene->addItem(*Iter);

             while (Iter != endIter){
                Shape *shape = *Iter;
                ++Iter;
                if (Iter != endIter){
                    Shape *tempShape = *Iter;

                    Arrow *arrow = new Arrow(shape->getBottomPoint(), tempShape->getUpperPoint(), FromBottomDirection);
                    myScene->addItem(arrow);
                }
           }

         }


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
    shapeContainer->addElement(block);
}

void CreateDiagramForm::on_ifBlockButton_clicked()
{
    IfBlock *ifBlock = new IfBlock(sceneCenterX, sceneCenterY);
    myScene->addItem(ifBlock);
    shapeContainer->addElement(ifBlock);
}

void CreateDiagramForm::on_endBlockButton_clicked()
{
     Exit *exit = new Exit(sceneCenterX, sceneCenterY);
     myScene->addItem(exit);
     shapeContainer->addElement(exit);
}

void CreateDiagramForm::on_barButton_clicked()
{
     Bar *bar = new Bar(sceneCenterX, sceneCenterY);
     myScene->addItem(bar);
     shapeContainer->addElement(bar);
}

void CreateDiagramForm::on_startBlockButton_clicked()
{
     Entrance *entrance = new Entrance(sceneCenterX, sceneCenterY);
     myScene->addItem(entrance);
     shapeContainer->addElement(entrance);
}

void CreateDiagramForm::on_clearSceneButton_clicked()
{
    myScene->clear();
}
