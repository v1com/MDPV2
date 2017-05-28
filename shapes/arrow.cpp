#include "shapes/arrow.h"
#include <QPainter>

Arrow::Arrow(QPoint fromPoint, QPoint toPoint, ShapeType shapeType) {
    if (fromPoint.y() >= toPoint.y()) {
        this->to = fromPoint;
        this->from = toPoint;
    }
    else {
        this->from = fromPoint;
        this->to = toPoint;
    }

    //if from_shape is IfBlock
    if (shapeType == IfBlockType){
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

void Arrow::updateFrom(QPoint fromPoint) {
    from = fromPoint;
}

void Arrow::updateTo(QPoint toPoint) {
    to = toPoint;
}

QPoint Arrow::getFrom() {
    return from;
}

QPoint Arrow::getTo() {
   return to;
}

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
