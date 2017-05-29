#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QWidget>
#include <QtWidgets>
#include <QPainter>
#include <QDebug>
#include "scene.h"
#include "shapetype.h"

class Shape : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Shape();

    virtual QRectF boundingRect() const override = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0;
    int getWidth();
    int getHeight();
    QPoint getCoords();

    virtual QPoint getBottomPoint() = 0;
    virtual QPoint getUpperPoint() = 0;
    virtual QPoint getRightPoint() = 0;
    virtual QPoint getLeftPoint() = 0;

    virtual QPoint getOutPoint() = 0;

    int getMyX();
    int getMyY();
    void setMyX(int x);
    void setMyY(int y);

    ShapeType getType();

public slots:
     void emitAddArrow();

signals:
     void addArrowSignal(Shape *fromShape);
     void mouseClicked(Shape *toShape);

protected:
    int myX, myY, myWidth, myHeight;

    ShapeType shapeType;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
};

#endif // SHAPE_H
