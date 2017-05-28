#include "entrance.h"
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QByteArray>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QDrag>

Entrance::Entrance(int x, int y)
{
    this->myX = x;
    this->myY = y;

    myWidth = 15;
    myHeight = 15;

    shapeType = EntranceType;

    setToolTip("Entrance");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}


void Entrance::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(* new QBrush(Qt::black));
    painter->drawEllipse(myX - myWidth / 2, myY - myHeight / 2, myWidth, myHeight);
}


QRectF Entrance::boundingRect() const
{
    return QRectF(myX - myWidth / 2, myY - myHeight / 2, myWidth, myHeight);
}

QPoint Entrance::getPointForOutArrow()
{
    return QPoint(myX, myY + myHeight / 2);
}

QPoint Entrance::getPointForInArrow()
{
    return QPoint(myX, myY - myHeight / 2);
}

