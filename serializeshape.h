#ifndef SERIALIZESHAPE_H
#define SERIALIZESHAPE_H

#include <shapes/shapetype.h>

#include <QString>

class SerializeShape
{
public:
    SerializeShape(int index, int shapeType, int x, int y, int w, int h, QString unicNumber);
    int index, x, y, w, h;
    int shapeType;
    QString unicNumber;
};

#endif // SERIALIZESHAPE_H
