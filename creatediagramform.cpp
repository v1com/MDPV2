#include "creatediagramform.h"
#include "ui_creatediagramform.h"
#include "scene.h"
#include "qtserialization.h"

#include <shapes/bar.h>
#include <shapes/block.h>
#include <shapes/entrance.h>
#include <shapes/exit.h>
#include <shapes/ifblock.h>

#include <diagram.h>

using namespace  std;

CreateDiagramForm::CreateDiagramForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateDiagramForm)
{
    ui->setupUi(this);
    ui->mainGraphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->mainGraphicsView->setRenderHint(QPainter::Antialiasing);

    myScene = new Scene();
//    connect(myScene,SIGNAL(changed(QList<QRectF>)),this,SLOT(clearAndPrint()));

    myScene->setSceneRect(ui->mainGraphicsView->pos().x(), ui->mainGraphicsView->pos().y(), ui->mainGraphicsView->width(), ui->mainGraphicsView->height());
    sceneCenterX = myScene->width() / 2;
    sceneCenterY = myScene->height() / 2;

    shapeContainer = new Diagram<Shape>; //= new Diagram<Shape>;

    //shapeContainer->addElement(block2);
    //shapeContainer->addLink(block1, block2);
    initDiargamOnScene(shapeContainer);


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

    connect(block, SIGNAL(addArrowSignal(Shape*)), this, SLOT(setArrowFrom(Shape*)));
    connect(block, SIGNAL(mouseClicked(Shape*)), this, SLOT(addArrow(Shape*)));
    connect(block, SIGNAL(shapeMoved()),this,SLOT(repain()));
}

void CreateDiagramForm::on_ifBlockButton_clicked()
{
    IfBlock *ifBlock = new IfBlock(sceneCenterX, sceneCenterY);
    myScene->addItem(ifBlock);
    shapeContainer->addElement(ifBlock);

    connect(ifBlock, SIGNAL(addArrowSignal(Shape*)), this, SLOT(setArrowFrom(Shape*)));
    connect(ifBlock, SIGNAL(mouseClicked(Shape*)), this, SLOT(addArrow(Shape*)));
    connect(ifBlock,SIGNAL(shapeMoved()),this,SLOT(repain()));
}

void CreateDiagramForm::on_endBlockButton_clicked()
{
     Exit *exit = new Exit(sceneCenterX, sceneCenterY);
     myScene->addItem(exit);
     shapeContainer->addElement(exit);

     connect(exit, SIGNAL(mouseClicked(Shape*)), this, SLOT(addArrow(Shape*)));
     connect(exit,SIGNAL(shapeMoved()),this,SLOT(repain()));
}

void CreateDiagramForm::on_barButton_clicked()
{
     Bar *bar = new Bar(sceneCenterX, sceneCenterY);
     myScene->addItem(bar);
     shapeContainer->addElement(bar);

     connect(bar, SIGNAL(addArrowSignal(Shape*)), this, SLOT(setArrowFrom(Shape*)));
     connect(bar, SIGNAL(mouseClicked(Shape*)), this, SLOT(addArrow(Shape*)));
     connect(bar, SIGNAL(shapeMoved()),this,SLOT(repain()));
}

void CreateDiagramForm::on_startBlockButton_clicked()
{
     Entrance *entrance = new Entrance(sceneCenterX, sceneCenterY);
     myScene->addItem(entrance);
     shapeContainer->addElement(entrance);

     connect(entrance, SIGNAL(addArrowSignal(Shape*)), this, SLOT(setArrowFrom(Shape*)));
     connect(entrance, SIGNAL(mouseClicked(Shape*)), this, SLOT(addArrow(Shape*)));
     connect(entrance,SIGNAL(shapeMoved()), this, SLOT(repain()));
}

void CreateDiagramForm::on_clearSceneButton_clicked()
{
    QList<QGraphicsItem*> items = myScene->items();
    for(int i = 0; i < items.size(); i++){
        myScene->removeItem(items[i]);
    }

    shapeContainer = new Diagram<Shape>;
}

void CreateDiagramForm::addArrow(Shape *to)
{
    if (arrowFrom) {
        Arrow *arrow = new Arrow(arrowFrom, to);
        myScene->addItem(arrow);
        arrows.append(arrow);
        shapeContainer->addLink(arrowFrom,to);
        myScene->update();
    }

    arrowFrom = NULL;
}

void CreateDiagramForm::setArrowFrom(Shape *from)
{
    this->arrowFrom = from;
}

void CreateDiagramForm::repain() {
    clearArrows();
    vector<list<Shape*>> v =  shapeContainer->getVector();
        for (int i = 0; i < v.size(); i++){
            list<Shape*>::iterator Iter = v[i].begin();
            list<Shape*>::iterator endIter = v[i].end();

            Shape *shape = *Iter;
            if(!myScene->items().contains(shape)) myScene->addItem(shape);

             while (Iter != endIter){
                ++Iter;
                if (Iter != endIter){
                    Shape *tempShape = *Iter;
                    Arrow *arrow = new Arrow(shape, tempShape);
                    myScene->addItem(arrow);
                    arrows.append(arrow);
                    myScene->update();
                }
           }
        }
}

void CreateDiagramForm::initDiargamOnScene(Diagram<Shape> *)
{
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
                Arrow *arrow = new Arrow(shape,tempShape);
                myScene->addItem(arrow);
                arrows.append(arrow);
                myScene->update();
            }
       }
    }
}

void CreateDiagramForm::clearArrows()
{
    for(int i = 0; i < arrows.size(); i++){
        myScene->removeItem(arrows[i]);
    }
    arrows.clear();
}

void CreateDiagramForm::on_saveButton_clicked()
{
    MySerialization *qt = new MySerialization;
    qt->saveToFile(shapeContainer);
    QMessageBox::warning(this,"Success","Saved Scene Data to File");
}

void CreateDiagramForm::on_loadButton_clicked()
{
    MySerialization *qt = new MySerialization;
    qt->loadFromFile(shapeContainer, this);
    repain();
    QMessageBox::warning(this,"Success","Loaded scene from file");
}
