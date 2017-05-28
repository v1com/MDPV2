#include "block.h"
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QByteArray>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QDrag>

Block::Block(int x, int y, int w, int h)
{
    this->myX = x;
    this->myY = y;
    this->myWidth = w;
    this->myHeight = h;

    shapeType = BlockType;

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
    painter->drawRect(myX - myWidth / 2, myY - myHeight / 2, myWidth, myHeight);
    painter->drawText(myX - myWidth / 2, myY - myHeight / 2, myWidth, myHeight, 0, "testtest\ntesttesttest");
}


QRectF Block::boundingRect() const
{
    return QRectF(myX - myWidth / 2, myY - myHeight / 2, myWidth, myHeight);
}

QPoint Block::getPointForOutArrow()
{
    return QPoint(myX, myY + myHeight / 2);
}

QPoint Block::getPointForInArrow()
{
    return QPoint(myX, myY - myHeight / 2);
}
