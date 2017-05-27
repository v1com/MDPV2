#include "arrow.h"
#include "shape.h"
#include <QtWidgets>
#include <QDrag>

Shape::Shape()
{
    setAcceptDrops(true);
    isDefault = false;
    arrowPos = new ArrowPosition();
}

int Shape::getWidth()
{
    return width;
}

int Shape::getHeight()
{
    return height;
}

QPoint Shape::getCoords() {
    return QPoint(myX, myY);
}

int Shape::getType()
{
    return type;
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

    QPixmap pixmap(pixmap_w, pixmap_h);
    pixmap.fill(Qt::white);

    QPainter painter(&pixmap);
    painter.translate(translate_x, translate_y); // ANYA THERE ARE NEED CHANGES
    painter.setRenderHint(QPainter::Antialiasing);
    paint(&painter, 0, 0);
    painter.end();

    pixmap.setMask(pixmap.createHeuristicMask());

    drag->setPixmap(pixmap);
    drag->setHotSpot(QPoint(15, 20));

   // drag->exec();
}

void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Shape::mouseReleaseEvent";
    setCursor(Qt::OpenHandCursor);

    if(isDefault) {
        return;
    } else {
//        QPoint arrowFromPosBeforeMoving = getArrowPos()->fromPosition;
//        QPoint arrowToPosBeforeMoving = getArrowPos()->toPosition;
//        ArrowPosition *arrowPosBeforeMoving = getArrowPos();
//        qDebug() << "1) arrowFromPosBeforeMoving" << arrowFromPosBeforeMoving;
//        qDebug() << "1) arrowToPosBeforeMoving" << arrowToPosBeforeMoving;

        myX = event->scenePos().x();
        myY = event->scenePos().y();

//        for(Arrow *arrow : myScene->arrowList) {
//            ArrowPosition *arrowFromPos = arrow->fromPos;
//            ArrowPosition *arrowToPos = arrow->toPos;

//            myScene->removeItem(arrow);
//            myScene->arrowList.removeOne(arrow);

//            Arrow *newArrow;
//            qDebug() << "2) arrowFromPos->fromPosition" << arrowFromPos->fromPosition;
//            qDebug() << "2) arrowFromPos->toPosition" << arrowFromPos->toPosition;
//            qDebug() << "3) arrowToPos->fromPosition" << arrowToPos->fromPosition;
//            qDebug() << "3) arrowToPos->toPosition" << arrowToPos->toPosition;

//            if((arrowFromPosBeforeMoving.x() == arrowFromPos->fromPosition.x()) &&
//                    (arrowFromPosBeforeMoving.y() == arrowFromPos->fromPosition.y()) &&
//                    (arrowToPosBeforeMoving.x() == arrowFromPos->toPosition.x()) &&
//                    (arrowToPosBeforeMoving.y() == arrowFromPos->toPosition.y())) {
//                newArrow = new Arrow(arrowPosBeforeMoving, getArrowPos());
//            } else {
//                newArrow = new Arrow(getArrowPos(), arrowPosBeforeMoving);
//            }

//            myScene->addItem(newArrow);
//            myScene->arrowList.append(newArrow);
//        }

        for(Arrow *arrow : arrowFromList) {
            ArrowPosition *arrowToPos = arrow->toPos;
            myScene->removeItem(arrow);
            arrowFromList.removeOne(arrow);

            arrow = new Arrow(getArrowPos(), arrowToPos);
            myScene->addItem(arrow);
            arrowFromList.append(arrow);
        }

        for(Arrow *arrow : arrowToList) {
            Arrow *newArrow = new Arrow(arrow->fromPos, getArrowPos());
            myScene->addItem(newArrow);
            arrowToList.append(newArrow);
            arrowToList.removeOne(arrow);
            myScene->removeItem(arrow);
        }

        myScene->update();
    }
}

//void Shape::dragEnterEvent ( QGraphicsSceneDragDropEvent * event )
//{
//    qDebug() << "Shape::dragEnterEvent ";
//}

//void Shape::dragLeaveEvent ( QGraphicsSceneDragDropEvent * event )
//{
//    qDebug() << "Shape::dragLeaveEvent";
//}

//void Shape::dragMoveEvent(QGraphicsSceneDragDropEvent * event )
//{
//    qDebug() << "Shape::dragMoveEvent";
//}

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
    Arrow *arrow = new Arrow(shape->getArrowPos(), this->getArrowPos());
    shape->arrowFromList.append(arrow);
    this->arrowToList.append(arrow);

    //myScene->arrowList.append(arrow);

    this->scene()->addItem(arrow);
    this->scene()->update();
}

ArrowPosition *Shape::getArrowPos()
{
    return new ArrowPosition(getArrowIn(), getArrowOut(), type);
}
