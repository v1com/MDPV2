#ifndef IFBLOCK_H
#define IFBLOCK_H
#include "arrow.h"
#include "shape.h"

class IfBlock : public Shape
{
public:
    IfBlock(int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPoint getPointForOutArrow();
    QPoint getPointForInArrow();


private:
    bool isFirstArrow = true;
};

#endif // IFBLOCK_H
