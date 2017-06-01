#include "bar.h"

Bar::Bar(int x, int y)
{
    this->myX = x;
    this->myY = y;

    shapeType = BarType;

    myWidth = 130;
    myHeight = 5;

    setToolTip("Bar");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void Bar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(* new QBrush(Qt::black));
    painter->drawRect(myX, myY, myWidth, myHeight);
}


QRectF Bar::boundingRect() const
{
    return QRectF(myX, myY, myWidth, myHeight);
}


QPoint Bar::getBottomPoint()
{
    return QPoint(myX + myWidth / 2, myY + myHeight);
}

QPoint Bar::getUpperPoint()
{
     return QPoint(myX + myWidth / 2, myY);
}

QPoint Bar::getLeftPoint()
{
    return QPoint(myX, myY + myHeight / 2);
}

QPoint Bar::getRightPoint()
{
    return QPoint(myX + myWidth, myY + myHeight / 2);
}

QPoint Bar::getOutPoint() {
    return getBottomPoint();
}
