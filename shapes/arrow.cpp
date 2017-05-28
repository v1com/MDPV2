#include "shapes/arrow.h"
#include <QPainter>

Arrow::Arrow(QPoint fromPoint, QPoint toPoint, ArrowDirection arrowDirection) {
    this->from = fromPoint;
    this->to = toPoint;

    switch (arrowDirection) {
        case FromBottomDirection:
            if (from.x() == to.x()) {
                lines.push_back(QLine(from, to));
            }
            else {
                int dist = abs(from.y() - to.y());
                lines.push_back(QLine(from, QPoint(from.x(), from.y() + dist / 4)));
                lines.push_back(QLine(QPoint(from.x(), from.y() + dist / 4), QPoint(to.x(), from.y() + dist / 4)));
                lines.push_back(QLine(QPoint(to.x(), from.y() + dist / 4), to));
            }
            break;

            //FOR IFBLOCK
        case FromLRtoDownDirection:
            if (from.y() == to.y()) {
                lines.push_back(QLine(from, to));
            }
            else {
                lines.push_back(QLine(from, QPoint(to.x(), from.y())));
                lines.push_back(QLine(QPoint(to.x(), from.y()), to));
            }
            break;

        case FromLRtoUpDirection:
            int dist = 20;
            lines.push_back(QLine(from, QPoint(from.x() + dist, from.y())));
            lines.push_back(QLine(QPoint(from.x() + dist, from.y()), QPoint(from.x() + dist, to.y() - dist)));
            lines.push_back(QLine(QPoint(from.x() + dist, to.y() - dist), QPoint(to.x(), to.y() - dist)));
            lines.push_back(QLine(QPoint(to.x(), to.y() - dist), to));
            break;
    }

    points[0] = to;
    points[1] = QPoint(to.x() - 5, to.y() - 5);
    points[2] = QPoint(to.x() + 5, to.y() - 5);
}

Arrow::Arrow(Shape *fromShape, Shape *toShape){
    from = fromShape->getOutPoint();
    to = toShape->getUpperPoint();

    if (from.y() < to.y()) {
        // FROM сверху, TO ровно под ним
        if (from.x() == to.x()) {
            lines.push_back(QLine(from, to));
        }
        // 2
        else {
            int dist = abs(from.y() - to.y());
            lines.push_back(QLine(from, QPoint(from.x(), from.y() + dist / 4)));
            lines.push_back(QLine(QPoint(from.x(), from.y() + dist / 4), QPoint(to.x(), from.y() + dist / 4)));
            lines.push_back(QLine(QPoint(to.x(), from.y() + dist / 4), to));
        }
    }
    else if (from.y() == to.y()) {
        // FROM  и TO на одном уровне
        if (from.x() != to.x()) {
            int dist = 10;
            lines.push_back(QLine(from, QPoint(from.x(), from.y() + dist)));

            lines.push_back(QLine(QPoint(from.x(), from.y() + dist),
                                  QPoint(from.x() + (to.x() - from.x()) / 2, from.y() + dist)));

            lines.push_back(QLine(QPoint(from.x() + (to.x() - from.x()) / 2, from.y() + dist),
                                  QPoint(from.x() + (to.x() - from.x()) / 2, to.y() - dist)));

            lines.push_back(QLine(QPoint(from.x() + (to.x() - from.x()) / 2, to.y() - dist),
                                  QPoint(to.x(), to.y() - dist)));

            lines.push_back(QLine(QPoint(to.x(), to.y() - dist), to));
        }
    }
    // FROM снизу, TO сверху
    else if (from.y() > to.y()) {
        int dist = 10;

        int sign = to.x() < from.x() ? 1 : -1;

        // Если FROM это IFBLOCK, то стрелка начинается сбоку, а не снизу
        int lastX;
        if (fromShape->getType() == IfBlockType) {
            if ((from.x() < fromShape->getMyX()) && (from.x() > to.x())) {
                sign = -sign;
                lines.push_back(QLine(from,
                                     QPoint(from.x() + sign * dist, from.y())));

                lastX = from.x() + sign * dist;
                lines.push_back(QLine(QPoint(lastX, from.y()),
                                      QPoint(lastX, to.y() - dist)));
            }
            else {
                lines.push_back(QLine(from,
                                     QPoint(from.x() + sign * fromShape->getWidth() + sign * dist, from.y())));

                lastX = from.x() + sign * fromShape->getWidth() + sign * dist;
                lines.push_back(QLine(QPoint(lastX, from.y()),
                                      QPoint(lastX, to.y() - dist)));
            }
        }
        else {
            lines.push_back(QLine(from, QPoint(from.x(), from.y() + dist)));

            lines.push_back(QLine(QPoint(from.x(), from.y() + dist),
                                 QPoint(from.x() + sign * fromShape->getWidth() + sign * dist, from.y() + dist)));

            lastX = from.x() + sign * fromShape->getWidth() + sign * dist;
            lines.push_back(QLine(QPoint(lastX, from.y() + dist),
                                  QPoint(lastX, to.y() - dist)));
        }

        lines.push_back(QLine(QPoint(lastX, to.y() - dist),
                              QPoint(to.x(), to.y() - dist)));

        lines.push_back(QLine(QPoint(to.x(), to.y() - dist), to));
    }

    points[0] = to;
    points[1] = QPoint(to.x() - 5, to.y() - 5);
    points[2] = QPoint(to.x() + 5, to.y() - 5);
}

void Arrow::updateFrom(QPoint fromPoint) {
    from = fromPoint;
}

void Arrow::updateTo(QPoint toPoint) {
    to = toPoint;
}

QPoint Arrow::getFrom() {
    return from;
}

QPoint Arrow::getTo() {
   return to;
}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(* new QBrush(Qt::black));

    foreach (QLine line, lines) {
        painter->drawLine(line);
    }

    painter->drawPolygon(points, 3);
}

QRectF Arrow::boundingRect() const
{
    return QRectF(from.x(), from.y(), to.x() - from.x(), to.y() - from.y());
}
