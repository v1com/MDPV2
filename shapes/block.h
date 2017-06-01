#ifndef Block_H
#define Block_H
#include "shape.h"

class Block : public Shape
{
public:
    Block(int x, int y, int w, int h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPoint getBottomPoint();
    QPoint getUpperPoint();
    QPoint getRightPoint();
    QPoint getLeftPoint();

    QPoint getOutPoint();

    void setText(std::string text);

private:
    std::string text = "";
};

#endif // Block_H
