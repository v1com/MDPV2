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
    virtual QPoint getPointForOutArrow() = 0;
    virtual QPoint getPointForInArrow() = 0;
    bool isDefault;
    int getMyX();
    int getMyY();
    void setMyX(int x);
    void setMyY(int y);

    ShapeType getType();

protected:
    int myX, myY, myWidth, myHeight;

    ShapeType shapeType;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SHAPE_H
