#ifndef QTSERIALIZATION_H
#define QTSERIALIZATION_H

#include "Scene.h"
#include "creatediagramform.h"
#include "diagram.h"
#include "serializeshape.h"
#include <QObject>

#include <shapes/shape.h>

class MySerialization : public QObject
{
    Q_OBJECT
public:
    MySerialization();
    void saveToFile(Diagram<Shape> *shapeContainer);
    void loadFromFile(Diagram<Shape> *shapeContainer, CreateDiagramForm *scene);
private:
    void parser(Diagram<Shape> *shapeContainer, QList<SerializeShape*> *SSList, CreateDiagramForm *scene);
    Shape* findShapeInContainer(Diagram<Shape> *shapeContainer, QString unicNumber);
    QString fileName;
};

#endif // QTSERIALIZATION_H
