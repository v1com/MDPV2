#include "entrance.h"

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

QPoint Entrance::getBottomPoint()
{
    return QPoint(myX, myY + myHeight / 2);
}

QPoint Entrance::getUpperPoint()
{
    return QPoint(myX, myY - myHeight / 2);
}

QPoint Entrance::getLeftPoint()
{
    return QPoint(myX - myWidth / 2, myY);
}

QPoint Entrance::getRightPoint()
{
    return QPoint(myX + myWidth / 2, myY);
}

QPoint Entrance::getOutPoint() {
    return getBottomPoint();
}
