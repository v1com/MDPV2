#include "arrow.h"
#include "shape.h"

Shape::Shape()
{
    unicNumber = QUuid::createUuid().toString();
}

QString Shape::getUnicNumber()
{
    return unicNumber;
}

void Shape::setUnicNumber(QString unicNumber)
{
    this->unicNumber = unicNumber;
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

void Shape::emitAddArrow()
{
    emit addArrowSignal(this);
}

void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit mouseClicked(this);
}

void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    myX = event->scenePos().x();
    myY = event->scenePos().y();
    this->scene()->update();
}

void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit shapeMoved();
}

void Shape::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu *menu = new QMenu;
    menu->addAction("Add arrow");
    menu->popup(event->screenPos());

    connect(menu, SIGNAL(triggered(QAction *)),
                 this, SLOT(emitAddArrow()));
}


