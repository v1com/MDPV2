#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsItem>
#include <QPoint>
#include <arrowposition.h>

class Arrow : public QGraphicsItem {
public:
    const static int DIRECTION_UP = 1, DIRECTION_DOWN = 2, DIRECTION_LEFT = 3, DIRECTION_RIGHT = 4;

    Arrow();
    //Arrow(QPoint from_point, QPoint to_point);
    //Arrow(QPoint from_point, Shape *to_shape, const int direction);
    Arrow(ArrowPosition *fromPos, ArrowPosition *toPos);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void updateFrom(ArrowPosition *fromPos);
    void updateTo(ArrowPosition *toPos);
    QPoint getFrom();
    QPoint getTo();
    ArrowPosition *fromPos;
    ArrowPosition *toPos;
    ArrowPosition *getFromPos();
    ArrowPosition *getToPos();

private:
    QPoint from;
    QPoint to;

    std::list <QLine> lines;
    // points for arrowhead's triangle
    QPoint points[3];
};

#endif // ARROW_H
