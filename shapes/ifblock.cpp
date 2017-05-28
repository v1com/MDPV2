#include "ifblock.h"

IfBlock::IfBlock(int x, int y)
{
    this->myX = x;
    this->myY = y;

    myWidth = 70;
    myHeight = 40;

    shapeType = IfBlockType;

    setToolTip("If block");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void IfBlock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(* new QBrush(Qt::gray));

    QPoint points[4] = {
        QPoint(myX - myWidth / 2, myY),
        QPoint(myX, myY - myHeight / 2),
        QPoint(myX + myWidth / 2, myY),
        QPoint(myX, myY + myHeight / 2),
    };
    painter->drawPolygon(points, 4);
}


QRectF IfBlock::boundingRect() const
{
    return QRectF(myX - myWidth / 2, myY - myHeight / 2, myWidth, myHeight);
}


QPoint IfBlock::getPointForOutArrow()
{
    if (isFirstArrow){
        isFirstArrow = false;
        return QPoint(myX - myWidth / 2, myY);
    }
    else {
        return QPoint(myX + myWidth / 2, myY);
    }
}

QPoint IfBlock::getPointForInArrow()
{
    return QPoint(myX, myY - myHeight / 2);
}
