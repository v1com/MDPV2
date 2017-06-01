#include "qtserialization.h"

#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QGraphicsItem>
#include <QDebug>

#include <shapes/bar.h>
#include <shapes/block.h>
#include <shapes/entrance.h>
#include <shapes/exit.h>
#include <shapes/ifblock.h>
#include <shapes/shape.h>

MySerialization::MySerialization()
{
    fileName = QDir::currentPath().append("/savedStructure.txt");
    qDebug(fileName.toLatin1());
}

void MySerialization::saveToFile(Diagram<Shape> *shapeContainer) {

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug("cant open");
        return;
    }

    QDataStream out(&file);
    vector<list<Shape*>> v =  shapeContainer->getVector();
    out << v.size();

    for (int i = 0; i < v.size(); i++) {
        Shape *shape = v[i].front();
        out << i;
        out << shape->getType();
        out << shape->getMyX();
        out << shape->getMyY();
        out << shape->getWidth();
        out << shape->getHeight();
        out << shape->getUnicNumber();
        out << shape->getName();
        out << shape->getDays();
        out << shape->getCost();
    }

    for (int i = 0; i < v.size(); i++) {
        out << v[i].size() - 1;

        list<Shape*>::iterator Iter = v[i].begin();
        list<Shape*>::iterator endIter = v[i].end();
        ++Iter;
        while (Iter != endIter) {
            Shape *shape = *Iter;
            out << shape->getUnicNumber();
            ++Iter;
        }
    }

    file.close();
}

void MySerialization::loadFromFile(Diagram<Shape> *shapeContainer, CreateDiagramForm *scene) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug("cant open");
        return;
    }

    QDataStream in(&file);
    int size = 0;
    in >> size;

    QList<SerializeShape*> *SSList = new QList<SerializeShape*>();

    for(int i = 0; i < size; i++)
    {
        int index = 0;
        int shapeType;
        int x = 0;
        int y = 0;
        int w = 0;
        int h = 0;
        int days = 0;
        int cost = 0;
        QString name = "";
        QString unicNumber;

        in >> index;
        in >> shapeType;
        in >> x;
        in >> y;
        in >> w;
        in >> h;
        in >> unicNumber;
        in >> name;
        in >> days;
        in >> cost;

        SerializeShape *ss = new SerializeShape(index, shapeType, x, y, w, h, unicNumber, name, days, cost);
        SSList->append(ss);
    }

    parser(shapeContainer, SSList, scene);

    vector<list<Shape*>> vec =  shapeContainer->getVector();

    for(int i = 0; i < size; i++)
    {
        int countOfLink = 0;
        in >> countOfLink;
        for(int j = 0; j < countOfLink; j++) {
            QString unicNumber;
            in >> unicNumber;
            shapeContainer->addLink(vec[i].front(), findShapeInContainer(shapeContainer, unicNumber));
        }
    }

    file.close();
}

void MySerialization::parser(Diagram<Shape> *shapeContainer, QList<SerializeShape*> *SSList, CreateDiagramForm *scene) {

    for(SerializeShape *sshape : *SSList) {
        if(sshape->shapeType == BlockType) {
            Block *block = new Block(sshape->x, sshape->y, sshape->w, sshape->h);
            block->setUnicNumber(sshape->unicNumber);
            shapeContainer->addElement(block);

            block->setName(sshape->name);
            block->setDays(sshape->days);
            block->setCost(sshape->cost);

            connect(block, SIGNAL(addArrowSignal(Shape*)), scene, SLOT(setArrowFrom(Shape*)));
            connect(block, SIGNAL(mouseClicked(Shape*)), scene, SLOT(addArrow(Shape*)));
            connect(block, SIGNAL(shapeMoved()), scene, SLOT(repain()));
        }

        if(sshape->shapeType == IfBlockType) {
            IfBlock *ifBlock = new IfBlock(sshape->x, sshape->y);
            ifBlock->setUnicNumber(sshape->unicNumber);
            shapeContainer->addElement(ifBlock);

            ifBlock->setName(sshape->name);
            ifBlock->setDays(sshape->days);
            ifBlock->setCost(sshape->cost);

            connect(ifBlock, SIGNAL(addArrowSignal(Shape*)), scene, SLOT(setArrowFrom(Shape*)));
            connect(ifBlock, SIGNAL(mouseClicked(Shape*)), scene, SLOT(addArrow(Shape*)));
            connect(ifBlock, SIGNAL(shapeMoved()), scene, SLOT(repain()));
        }

        if(sshape->shapeType == BarType) {
            Bar *bar = new Bar(sshape->x, sshape->y);
            bar->setUnicNumber(sshape->unicNumber);
            shapeContainer->addElement(bar);

            bar->setName(sshape->name);
            bar->setDays(sshape->days);
            bar->setCost(sshape->cost);

            connect(bar, SIGNAL(addArrowSignal(Shape*)), scene, SLOT(setArrowFrom(Shape*)));
            connect(bar, SIGNAL(mouseClicked(Shape*)), scene, SLOT(addArrow(Shape*)));
            connect(bar, SIGNAL(shapeMoved()), scene, SLOT(repain()));
        }

        if(sshape->shapeType == ExitType) {
            Exit *exit = new Exit(sshape->x, sshape->y);
            exit->setUnicNumber(sshape->unicNumber);
            shapeContainer->addElement(exit);

            exit->setName(sshape->name);
            exit->setDays(sshape->days);
            exit->setCost(sshape->cost);

            connect(exit, SIGNAL(addArrowSignal(Shape*)), scene, SLOT(setArrowFrom(Shape*)));
            connect(exit, SIGNAL(mouseClicked(Shape*)), scene, SLOT(addArrow(Shape*)));
            connect(exit, SIGNAL(shapeMoved()), scene, SLOT(repain()));
        }

        if(sshape->shapeType == EntranceType) {
            Entrance *entrance = new Entrance(sshape->x, sshape->y);
            entrance->setUnicNumber(sshape->unicNumber);
            shapeContainer->addElement(entrance);

            entrance->setName(sshape->name);
            entrance->setDays(sshape->days);
            entrance->setCost(sshape->cost);

            connect(entrance, SIGNAL(addArrowSignal(Shape*)), scene, SLOT(setArrowFrom(Shape*)));
            connect(entrance, SIGNAL(mouseClicked(Shape*)), scene, SLOT(addArrow(Shape*)));
            connect(entrance, SIGNAL(shapeMoved()), scene, SLOT(repain()));
        }
    }
}

Shape* MySerialization::findShapeInContainer(Diagram<Shape> *shapeContainer, QString unicNumber) {
    vector<list<Shape*>> v =  shapeContainer->getVector();
    for (int i = 0; i < v.size(); i++) {
        Shape *shape = v[i].front();
        if(shape->getUnicNumber() == unicNumber) {
            return shape;
        }
    }
}


