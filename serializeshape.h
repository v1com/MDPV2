#ifndef SERIALIZESHAPE_H
#define SERIALIZESHAPE_H

#include <shapes/shapetype.h>

#include <QString>

class SerializeShape
{
public:
    SerializeShape(int index, int shapeType, int x, int y, int w, int h, QString unicNumber, QString name, int days, int cost);
    int index, x, y, w, h;
    int shapeType;
    int days = 0;
    int cost = 0;
    QString name = "";
    QString unicNumber;
};

#endif // SERIALIZESHAPE_H
