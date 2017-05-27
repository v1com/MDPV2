#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>
#include <QGraphicsView>
#include <arrowposition.h>
#include <scene.h>

class Shape : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Shape();

    virtual QRectF boundingRect() const override = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0;
    virtual void addArrows(QGraphicsScene *scene) = 0;
    int getWidth();
    int getHeight();
    QPoint getCoords();
    virtual QPoint getArrowOut() = 0;
    virtual QPoint getArrowIn() = 0;
    bool isDefault;
    ArrowPosition *arrowPos;
    ArrowPosition *getArrowPos();
    QList<Arrow*> arrowFromList;
    QList<Arrow*> arrowToList;

    int getType();

protected:
    int myX, myY, width, height;
    int pixmap_w, pixmap_h;
    int translate_x, translate_y;
    //number of vertex
    int n_vertex;

    QPoint arrow_out;
    QPoint arrow_in;

    int type;

    Scene *myScene;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

//    void dragEnterEvent(QGraphicsSceneDragDropEvent * event) override;
//    void dragLeaveEvent(QGraphicsSceneDragDropEvent * event) override;
//    void dragMoveEvent(QGraphicsSceneDragDropEvent * event) override;
    void dropEvent(QGraphicsSceneDragDropEvent * event) override;
};

#endif // SHAPE_H
