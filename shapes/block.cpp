#include "block.h"


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
    painter->drawText(myX - myWidth / 2 + 5, myY - myHeight / 2 + 5, myWidth - 5, myHeight - 5, 0, text.c_str());
}


QRectF Block::boundingRect() const
{
    return QRectF(myX - myWidth / 2, myY - myHeight / 2, myWidth, myHeight);
}

QPoint Block::getBottomPoint()
{
    return QPoint(myX, myY + myHeight / 2);
}

QPoint Block::getUpperPoint()
{
    return QPoint(myX, myY - myHeight / 2);
}

QPoint Block::getLeftPoint()
{
    return QPoint(myX - myWidth / 2, myY);
}

QPoint Block::getRightPoint()
{
    return QPoint(myX + myWidth / 2, myY);
}

QPoint Block::getOutPoint() {
    return getBottomPoint();
}

void Block::setText(std::string text)
{
    this->text = text;
}
