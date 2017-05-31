#ifndef QTSERIALIZATION_H
#define QTSERIALIZATION_H

#include "Scene.h"
#include "diagram.h"
#include "serializeshape.h"

#include <shapes/shape.h>

class MySerialization
{
public:
    MySerialization();
    void saveToFile(Diagram<Shape> *shapeContainer);
    void loadFromFile(Diagram<Shape> *shapeContainer);
private:
    void parser(Diagram<Shape> *shapeContainer, QList<SerializeShape*> *SSList);
    QString fileName;
};

#endif // QTSERIALIZATION_H
