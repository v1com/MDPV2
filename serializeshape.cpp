#include "serializeshape.h"

SerializeShape::SerializeShape(int index, int shapeType, int x, int y, int w, int h, QString unicNumber, QString name, int days, int cost)
{
    this->index = index;
    this->shapeType = shapeType;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->unicNumber = unicNumber;
    this->name = name;
    this->days = days;
    this->cost = cost;
}
