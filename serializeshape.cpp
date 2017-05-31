#include "serializeshape.h"

SerializeShape::SerializeShape(int index, int shapeType, int x, int y, int w, int h, QString unicNumber)
{
    this->index = index;
    this->shapeType = shapeType;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->unicNumber = unicNumber;
}
