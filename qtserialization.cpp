#include "qtserialization.h"

#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QGraphicsItem>
#include <QDebug>

#include <shapes/block.h>
#include <shapes/shape.h>

MySerialization::MySerialization()
{
    fileName = QDir::currentPath().append("/savedStructure.txt");
}

void MySerialization::saveToFile(Diagram<Shape> *shapeContainer) {
    qDebug(fileName.toLatin1());
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
    }

    out << "MDP";

    for (int i = 0; i < v.size(); i++) {
        out << v[i].size();

        for(Shape *shape : v[i]) {
            qDebug() << shape->getUnicNumber();
            out << shape->getUnicNumber();
        }
    }

    file.close();
}

void MySerialization::loadFromFile(Diagram<Shape> *shapeContainer) {
    qDebug(fileName.toLatin1());
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
        QString unicNumber;

        in >> index;
        in >> shapeType;
        in >> x;
        in >> y;
        in >> w;
        in >> h;
        in >> unicNumber;

        SerializeShape *ss = new SerializeShape(index, shapeType, x, y, w, h, unicNumber);
        SSList->append(ss);
    }

    parser(shapeContainer, SSList);

    for(int i = 0; i < size; i++)
    {
        int countOfLink = 0;
        in >> countOfLink;

    }

    file.close();
}

void MySerialization::parser(Diagram<Shape> *shapeContainer, QList<SerializeShape*> *SSList) {

    for(SerializeShape *sshape : *SSList) {
        if(sshape->shapeType == BlockType) {
            shapeContainer->addElement(new Block(sshape->x, sshape->y, sshape->w, sshape->h));
        }
    }
}
