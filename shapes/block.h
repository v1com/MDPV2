#ifndef Block_H
#define Block_H
#include "shape.h"
#include "arrow.h"

class Block : public Shape
{
public:
    Block(int x, int y, int w, int h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPoint getPointForOutArrow();
    QPoint getPointForInArrow();
};

#endif // Block_H
