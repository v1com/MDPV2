#include "exit.h"
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QByteArray>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QDrag>

Exit::Exit(Scene *tmpScene, int x, int y)
{
    myScene = tmpScene;
    this->myX = x;
    this->myY = y;

    type = 2;

    width = height = outer_d;
    //Offset in order to the figures are not cut off
    pixmap_w = outer_d + 2;
    pixmap_h = outer_d + 2;

    translate_x = - x + 1;
    translate_y = - y + 1;

    setToolTip("Exit");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void Exit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));

    painter->setBrush(* new QBrush(Qt::gray));
    painter->drawEllipse(myX, myY, outer_d,outer_d);

    painter->setBrush(* new QBrush(Qt::black));
    painter->drawEllipse(myX + 5, myY + 5, inner_d, inner_d);
}

void Exit::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(!isDefault) {
        qDebug() << "Block::mouseDoubleClickEvent";
        QMimeData * mimeData = new QMimeData;

        Shape * item = this;
        QByteArray byteArray(reinterpret_cast<char*>(&item),sizeof(Shape*));
        mimeData->setData("Item",byteArray);

        // start the event
        QDrag * drag = new QDrag(event->widget());
        drag->setMimeData(mimeData);
        drag->exec();
    } else {
        myScene->addItem(new Exit(myScene, 200, 200));
    }
}

void Exit::addArrows(QGraphicsScene *scene){}

QRectF Exit::boundingRect() const
{
    return QRectF(myX, myY, outer_d, outer_d);
}

QPoint Exit::getArrowOut()
{
    return QPoint(myX + width / 2, myY + height);
}

QPoint Exit::getArrowIn()
{
    return QPoint(myX + width / 2, myY);
}

