#include "shapes/arrow.h"
#include <QPainter>

Arrow::Arrow() {

}

Arrow::Arrow(ArrowPosition *fromPos, ArrowPosition *toPos)
{
    if (fromPos->fromPosition.y() > toPos->toPosition.y()){
        this->toPos = fromPos;
        this->fromPos = toPos;
        to = fromPos->toPosition;
        from = toPos->fromPosition;
    }
    else {
        this->fromPos = fromPos;
        this->toPos = toPos;
        from = fromPos->fromPosition;
        to = toPos->toPosition;
    }

    //if from_shape is IfBlock
    if (this->fromPos->shapeType == IfBlockType){
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
