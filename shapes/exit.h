#ifndef EXIT_H
#define EXIT_H
#include "shape.h"

class Exit : public Shape
{
public:
    Exit(Scene *tmpScene, int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void addArrows(QGraphicsScene *scene);
    QRectF boundingRect() const override;
    QPoint getArrowOut();
    QPoint getArrowIn();
protected:
     void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
private:
    const int inner_d = 15;
    const int outer_d = 25;
};

#endif // EXIT_H
