#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsItem>
#include <QPoint>
#include "arrowdirection.h"
#include "shape.h"

class Arrow : public QGraphicsItem {
public:
    Arrow(QPoint fromPoint, QPoint toPoint, ArrowDirection arrowDirection);

    Arrow(Shape *fromShape, Shape *toShape);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPoint getFrom();
    QPoint getTo();

    void updateFrom(QPoint fromPoint);
    void updateTo(QPoint toPoint);

    void drawTriangle();

private:
    QPoint from;
    QPoint to;

    std::list <QLine> lines;
    // points for arrowhead's triangle
    QPoint points[3];
};

#endif // ARROW_H
