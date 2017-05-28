#include "exit.h"

Exit::Exit(int x, int y)
{
    this->myX = x;
    this->myY = y;

    shapeType = ExitType;

    myWidth = myHeight = outerD;

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
    painter->drawEllipse(myX - myWidth / 2, myY - myHeight / 2, outerD, outerD);

    painter->setBrush(* new QBrush(Qt::black));
    painter->drawEllipse(myX - myWidth / 2 + 5, myY - myHeight / 2 + 5, innerD, innerD);
}


QRectF Exit::boundingRect() const
{
    return QRectF(myX - myWidth / 2, myY - myHeight / 2, outerD, outerD);
}

QPoint Exit::getBottomPoint()
{
    return QPoint(myX, myY + myHeight / 2);
}

QPoint Exit::getUpperPoint()
{
    return QPoint(myX, myY - myHeight / 2);
}

QPoint Exit::getLeftPoint()
{
    return QPoint(myX - myWidth / 2, myY);
}

QPoint Exit::getRightPoint()
{
    return QPoint(myX + myWidth / 2, myY);
}

