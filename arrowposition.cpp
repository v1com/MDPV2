#include "arrowposition.h"

ArrowPosition::ArrowPosition()
{

}

ArrowPosition::ArrowPosition(QPoint in, QPoint out, int type)
{
    toPosition = in;
    fromPosition = out;
    shapeType = type;
}
