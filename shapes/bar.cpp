#include "bar.h"
#include <QWidget>
#include <QtWidgets>
#include <QPainter>
#include <QDebug>
#include <QByteArray>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QDrag>

Bar::Bar(int x, int y)
{
    this->myX = x;
    this->myY = y;

    shapeType = BarType;

    myWidth = 100;
    myHeight = 5;

    setToolTip("Bar");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void Bar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(* new QBrush(Qt::black));
    painter->drawRect(myX, myY, myWidth, myHeight);
}


QRectF Bar::boundingRect() const
{
    return QRectF(myX, myY, myWidth, myHeight);
}

void Bar::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu *menu = new QMenu;
    menu->addAction("Add arrow");
    menu->addAction("Delete arrow");
    menu->popup(event->screenPos());

    QObject::connect(menu, SIGNAL(triggered(QAction *)),
                     this, SLOT(setWidth(QAction *)));
}


QPoint Bar::getPointForOutArrow()
{
    if (isFirstOutArrow) {
        isFirstOutArrow = false;
        return QPoint(myX + myWidth / 2, myY + myHeight);
    }
    else {
        auto myScene = scene();
        myWidth += 110;
        myScene->update();
        return QPoint(myX + myWidth - 50, myY + myHeight);
    }
}

QPoint Bar::getPointForInArrow()
{
    if (isFirstInArrow) {
        isFirstInArrow = false;
        return QPoint(myX + myWidth / 2, myY);
    }
    else {
        auto myScene = scene();
        myWidth += 110;
        myScene->update();
        return QPoint(myX + myWidth - 50, myY);
    }

}
