#include "arrow.h"
#include "shape.h"
#include <QtWidgets>
#include <QDrag>

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
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
        .length() < QApplication::startDragDistance()) {
        return;
    }

    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    drag->setMimeData(mime);

    mime->setColorData(QRectF(-15.5, -15.5, 34, 34));
    mime->setText("Data");


   // drag->exec();
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

void Shape::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    //Add arrow
    qDebug() << "shape drop event";

    QByteArray byteArray = event->mimeData()->data("Item");
    QByteArray *newArray = new QByteArray();
    newArray->append(byteArray.data());
    Shape *shape = *reinterpret_cast<Shape**>(byteArray.data());

    if(isDefault) {
        return;
    }

    qDebug() << "shape drop event x = " << shape->getCoords().x() << " y = " << shape->getCoords().y();
}

