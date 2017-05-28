#ifndef BAR_H
#define BAR_H
#include "shape.h"


class Bar : public Shape
{
    Q_OBJECT
public:
    Bar(int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    QPoint getBottomPoint();
    QPoint getUpperPoint();
    QPoint getRightPoint();
    QPoint getLeftPoint();

private:
    bool isFirstOutArrow = true;
    bool isFirstInArrow = true;
};

#endif // BAR_H
