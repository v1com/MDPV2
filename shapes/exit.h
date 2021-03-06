#ifndef EXIT_H
#define EXIT_H
#include "shape.h"

class Exit : public Shape
{
public:
    Exit(int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPoint getBottomPoint();
    QPoint getUpperPoint();
    QPoint getRightPoint();
    QPoint getLeftPoint();

    QPoint getOutPoint();

private:
    const int innerD = 15;
    const int outerD = 25;
};

#endif // EXIT_H
