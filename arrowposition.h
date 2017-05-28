#ifndef ARROWPOSITION_H
#define ARROWPOSITION_H

#include <QPoint>
#include "shapes/shapetype.h"

class ArrowPosition
{
public:
    ArrowPosition();
    ArrowPosition(QPoint in, QPoint out, int type);
    QPoint fromPosition;
    QPoint toPosition;
    int shapeType;

};

#endif // ARROWPOSITION_H
