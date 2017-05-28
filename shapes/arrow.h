#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsItem>
#include <QPoint>
#include "shapetype.h"

class Arrow : public QGraphicsItem {
public:
    Arrow(QPoint fromPoint, QPoint toPoint, ShapeType shapeType);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPoint getFrom();
    QPoint getTo();

    void updateFrom(QPoint fromPoint);
    void updateTo(QPoint toPoint);

private:
    QPoint from;
    QPoint to;

    std::list <QLine> lines;
    // points for arrowhead's triangle
    QPoint points[3];
};

#endif // ARROW_H
