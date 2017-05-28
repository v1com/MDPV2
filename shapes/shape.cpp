#include "arrow.h"
#include "shape.h"

Shape::Shape()
{
    setAcceptDrops(true);
    isDefault = false;
}

int Shape::getWidth()
{
    return myWidth;
}

int Shape::getHeight()
{
    return myHeight;
}

QPoint Shape::getCoords() {
    return QPoint(myX, myY);
}

int Shape::getMyX()
{
    return myX;
}

int Shape::getMyY()
{
    return myY;
}

void Shape::setMyX(int x) {
    myX = x;
}

void Shape::setMyY(int y) {
    myY = y;
}

ShapeType Shape::getType()
{
    return shapeType;
}

void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ClosedHandCursor);

    if(event->button() == Qt::RightButton)
    {
        qDebug() << "Shape::PressRightButton";
    } else {
        qDebug() << "Shape::PressLeftButton";
    }

}

void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}

void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Shape::mouseReleaseEvent";
    setCursor(Qt::OpenHandCursor);

    if(isDefault) {
        return;
    } else {
        myX = event->scenePos().x();
        myY = event->scenePos().y();
    }

}


