#ifndef ENTRANCE_H
#define ENTRANCE_H
#include "shape.h"
#include "arrow.h"

class Entrance : public Shape
{
public:
    Entrance(int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPoint getPointForOutArrow();
    QPoint getPointForInArrow();

};

#endif // ENTRANCE_H
