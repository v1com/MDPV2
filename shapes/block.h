#ifndef Block_H
#define Block_H
#include "shape.h"
#include "arrow.h"

class Block : public Shape
{
public:
    Block(Scene *tmpScene, int x, int y, int w, int h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void addArrows(QGraphicsScene *scene);
    QRectF boundingRect() const override;
    QPoint getArrowOut();
    QPoint getArrowIn();
protected:
     void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
private:
    int h, w;

    Arrow *arrow;
};

#endif // Block_H
