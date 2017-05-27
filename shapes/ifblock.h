#ifndef IFBLOCK_H
#define IFBLOCK_H
#include "arrow.h"
#include "shape.h"

class IfBlock : public Shape
{
public:
    IfBlock(Scene *tmpScene, int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void addArrows(QGraphicsScene *scene);
    QRectF boundingRect() const override;
    QPoint getArrowOut();
    QPoint getArrowIn();
protected:
     void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);


private:
    const int w = 70;
    const int h = 40;
    bool is_first_arrow = true;

    Arrow *left_arrow, *right_arrow;
};

#endif // IFBLOCK_H
