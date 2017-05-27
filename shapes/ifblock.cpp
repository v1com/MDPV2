#include "ifblock.h"
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QByteArray>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QDrag>

IfBlock::IfBlock(Scene *tmpScene, int x, int y)
{
    myScene = tmpScene;
    this->myX = x;
    this->myY = y;

    width = w;
    height = h;

    type = 4;

    //Offset in order to the figures are not cut off
    pixmap_w = w + 2;
    pixmap_h = h + 2;

    translate_x = - x + 1;
    translate_y = - y + 1;

    setToolTip("If block");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void IfBlock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(* new QBrush(Qt::gray));

    QPoint points[4] = {
        QPoint(myX, myY + h / 2),
        QPoint(myX + w / 2, myY + h),
        QPoint(myX + w, myY + h / 2),
        QPoint(myX + w / 2, myY),
    };
    painter->drawPolygon(points, 4);
}

void IfBlock::addArrows(QGraphicsScene *scene) {
    scene->addItem(left_arrow);
    scene->addItem(right_arrow);
}

QRectF IfBlock::boundingRect() const
{
    return QRectF(myX, myY, w, h);
}

void IfBlock::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(!isDefault) {
        qDebug() << "Block::mouseDoubleClickEvent";
        QMimeData * mimeData = new QMimeData;

        Shape * item = this;
        QByteArray byteArray(reinterpret_cast<char*>(&item),sizeof(Shape*));
        mimeData->setData("Item",byteArray);

        // start the event
        QDrag * drag = new QDrag(event->widget());
        drag->setMimeData(mimeData);
        drag->exec();
    } else {
        myScene->addItem(new IfBlock(myScene, 200, 200));
    }
}

QPoint IfBlock::getArrowOut()
{
    if (is_first_arrow){
        is_first_arrow = false;
        return QPoint(myX, myY + h / 2);
    }
    else {
        return QPoint(myX + w, myY + h / 2);
    }
}

QPoint IfBlock::getArrowIn()
{
    return QPoint(myX + w / 2, myY);
}
