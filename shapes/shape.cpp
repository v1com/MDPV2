#include "arrow.h"
#include "shape.h"

Shape::Shape()
{

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

}

void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    myX = event->scenePos().x();
    myY = event->scenePos().y();
    this->scene()->update();
}

void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}


