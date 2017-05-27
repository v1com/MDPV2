#include "bar.h"
#include <QWidget>
#include <QtWidgets>
#include <QPainter>
#include <QDebug>
#include <QByteArray>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QDrag>

Bar::Bar(Scene *tmpScene, int x, int y)
{
    myScene = tmpScene;
    this->myX = x;
    this->myY = y;
    w = 100;

    width = w;
    height = h;

    type = 3;

    //Offset in order to the figures are not cut off
    pixmap_w = w + 2;
    pixmap_h = h + 2;

    translate_x = - x + 1;
    translate_y = - y + 1;

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
    painter->drawRect(myX, myY, w, h);
}

void Bar::addArrows(QGraphicsScene *scene){
    foreach (Arrow *arrow, arrows) {
        scene->addItem(arrow);
    }
}

QRectF Bar::boundingRect() const
{
    return QRectF(myX, myY, w, h);
}

//void Bar::setWidth(QAction *action)
//{
//    auto myScene = scene();
//    if (action->text() == "Add arrow") {
//        w += 110;
//        Arrow *last = arrows.back();
//        arrows.push_back(new Arrow(QPoint(last->getFrom().x() + 110, myY + h),
//                                   QPoint(last->getFrom().x() + 110, myY + h + 30)));

//        myScene->addItem(arrows.back());
//    }
//    else if (action->text() == "Delete arrow") {
//        if (arrows.size() > 2) {
//            w -= 110;

//            myScene->removeItem(arrows.back());
//            arrows.pop_back();
//        }
//    }

//    pixmap_w = w + 2;
//    pixmap_h = h + 2;

//    myScene->update();
//}

void Bar::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu *menu = new QMenu;
    menu->addAction("Add arrow");
    menu->addAction("Delete arrow");
    menu->popup(event->screenPos());

    QObject::connect(menu, SIGNAL(triggered(QAction *)),
                     this, SLOT(setWidth(QAction *)));
}

void Bar::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
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
        myScene->addItem(new Bar(myScene, 200, 200));
    }
}

QPoint Bar::getArrowOut()
{
    if (is_first_arrow) {
        is_first_arrow = false;
        return QPoint(myX + w / 2, myY + h);
    }
    else {
        auto myScene = scene();
        w += 110;
        myScene->update();
        return QPoint(myX + w - 50, myY + h);
    }
}

QPoint Bar::getArrowIn()
{
    if (is_first_in_arrow) {
        is_first_in_arrow = false;
        return QPoint(myX + w / 2, myY);
    }
    else {
        auto myScene = scene();
        w += 110;
        myScene->update();
        return QPoint(myX + w - 50, myY);
    }

}
