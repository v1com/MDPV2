#include "block.h"
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QByteArray>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QDrag>

Block::Block(Scene *tmpScene, int x, int y, int w, int h)
{
    myScene = tmpScene;
    this->myX = x;
    this->myY = y;
    this->w = width = w;
    this->h = height = h;
    this->type = 0;

    this->arrowPos = new ArrowPosition(getArrowIn(), getArrowOut(), getType());

    //Offset in order to the figures are not cut off
    pixmap_w = w + 2;
    pixmap_h = h + 2;

    translate_x = - x + 1;
    translate_y = - y + 1;

    setToolTip("Simple block");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(* new QBrush(Qt::gray));
    painter->drawRect(myX, myY, w, h);
    painter->drawText(myX, myY, w, h, 0, "testtest\ntesttesttest");
}

void Block::addArrows(QGraphicsScene *scene){
    scene->addItem(arrow);
}

QRectF Block::boundingRect() const
{
    return QRectF(myX, myY, w, h);
}

void Block::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(!isDefault) {
        qDebug() << "Block::mouseDoubleClickEvent x = " << this->getCoords().x() << " y = " << this->getCoords().y();
        QMimeData * mimeData = new QMimeData;

        Shape * item = this;
        QByteArray byteArray(reinterpret_cast<char*>(&item),sizeof(Shape*));
        mimeData->setData("Item",byteArray);

        // start the event
        QDrag * drag = new QDrag(event->widget());
        drag->setMimeData(mimeData);
        drag->exec();
    } else {
        myScene->addItem(new Block(myScene, 200, 200, w, h));
    }
}

QPoint Block::getArrowOut()
{
    return QPoint(myX + w / 2, myY + h);
}

QPoint Block::getArrowIn()
{
    return QPoint(myX + w / 2, myY);
}
