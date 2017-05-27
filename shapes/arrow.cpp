#include "shapes/arrow.h"
#include <QPainter>

Arrow::Arrow() {

}

//Arrow::Arrow(QPoint from_point, QPoint to_point){
//    from = from_point;
//    to = to_point;

//    if (from.x() == to.x()) {
//        lines.push_back(QLine(from, to));
//    }
//    else {
//        lines.push_back(QLine(from, QPoint(to.x(), from.y())));
//        lines.push_back(QLine(QPoint(to.x(), from.y()), to));
//    }

//    points[0] = to;
//    points[1] = QPoint(to.x() - 5, to.y() - 5);
//    points[2] = QPoint(to.x() + 5, to.y() - 5);
//}

void Arrow::updateFrom(ArrowPosition *fromPos) {
    from = fromPos->fromPosition;
}

void Arrow::updateTo(ArrowPosition *toPos) {
    to = toPos->toPosition;
}

ArrowPosition *Arrow::getFromPos() {
    return this->fromPos;
}

ArrowPosition *Arrow::getToPos() {
   return this->toPos;
}

QPoint Arrow::getFrom() {
    return from;
}

QPoint Arrow::getTo() {
   return to;
}

Arrow::Arrow(ArrowPosition *fromPos, ArrowPosition *toPos)
{
    this->fromPos = fromPos;
    this->toPos = toPos;
    from = fromPos->fromPosition;
    to = toPos->toPosition;

    //if from_shape is IfBlock
    if (fromPos->shapeType == 4){
        if (from.y() == to.y()) {
            lines.push_back(QLine(from, to));
        }
        else {
            lines.push_back(QLine(from, QPoint(to.x(), from.y())));
            lines.push_back(QLine(QPoint(to.x(), from.y()), to));
        }
    }
    else {
        if (from.x() == to.x()) {
            lines.push_back(QLine(from, to));
        }
        else {
            int dist = abs(from.y() - to.y());
            lines.push_back(QLine(from, QPoint(from.x(), from.y() + dist / 4)));
            lines.push_back(QLine(QPoint(from.x(), from.y() + dist / 4), QPoint(to.x(), from.y() + dist / 4)));
            lines.push_back(QLine(QPoint(to.x(), from.y() + dist / 4), to));
        }
    }

    points[0] = to;
    points[1] = QPoint(to.x() - 5, to.y() - 5);
    points[2] = QPoint(to.x() + 5, to.y() - 5);
}


//Arrow::Arrow(QPoint from_point, Shape *to_shape, const int direction)
//{
//    from = from_point;

//    switch (direction) {
//        case DIRECTION_UP:
//            to.setX(to_shape->getCoords().x() + to_shape->getWidth() / 2);
//            to.setY(to_shape->getCoords().y() + to_shape->getHeight());

//            if(from.x() == to.x()) { //elements on the same level
//                lines.push_back(QLine(from, to));
//            }
//            else {
//                lines.push_back(QLine(from, QPoint(to.x(), from.y())));
//                lines.push_back(QLine(QPoint(to.x(), from.y()), to));
//            }

//            points[0] = to;
//            points[1] = QPoint(to.x() - 5, to.y() + 5);
//            points[2] = QPoint(to.x() + 5, to.y() + 5);

//            break;

//        case DIRECTION_DOWN:
//            to.setX(to_shape->getCoords().x() + to_shape->getWidth() / 2);
//            to.setY(to_shape->getCoords().y());

//            if(from.x() == to.x()) { //elements on the same level
//                lines.push_back(QLine(from, to));
//            }
//            else {
//                lines.push_back(QLine(from, QPoint(to.x(), from.y())));
//                lines.push_back(QLine(QPoint(to.x(), from.y()), to));
//            }

//            points[0] = to;
//            points[1] = QPoint(to.x() - 5, to.y() - 5);
//            points[2] = QPoint(to.x() + 5, to.y() - 5);

//            break;

//        case DIRECTION_LEFT:
//            to.setX(to_shape->getCoords().x() + to_shape->getWidth());
//            to.setY(to_shape->getCoords().y() + to_shape->getHeight() / 2);

//            if(from.x() == to.x()) { //elements on the same level
//                lines.push_back(QLine(from, to));
//            }
//            else {
//                lines.push_back(QLine(from, QPoint(from.x(), to.y())));
//                lines.push_back(QLine(QPoint(from.x(), to.y()), to));
//            }

//            points[0] = to;
//            points[1] = QPoint(to.x() + 5, to.y() - 5);
//            points[2] = QPoint(to.x() + 5, to.y() + 5);

//            break;

//        case DIRECTION_RIGHT:
//            to.setX(to_shape->getCoords().x() + to_shape->getWidth());
//            to.setY(to_shape->getCoords().y() + to_shape->getHeight() / 2);

//            if(from.x() == to.x()) { //elements on the same level
//                lines.push_back(QLine(from, to));
//            }
//            else {
//                lines.push_back(QLine(from, QPoint(from.x(), to.y())));
//                lines.push_back(QLine(QPoint(from.x(), to.y()), to));
//            }

//            points[0] = to;
//            points[1] = QPoint(to.x() - 5, to.y() - 5);
//            points[2] = QPoint(to.x() - 5, to.y() + 5);

//            break;

//        default:
//            break;
//    }

//}


void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(* new QBrush(Qt::black));

    foreach (QLine line, lines) {
        painter->drawLine(line);
    }

    painter->drawPolygon(points, 3);
}

QRectF Arrow::boundingRect() const
{
    return QRectF(from.x(), from.y(), to.x() - from.x(), to.y() - from.y());
}
