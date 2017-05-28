#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "Scene.h"

class View: public QGraphicsView
{
public:
    View(Scene * scene, int i);

private:
    Scene * scene_;
    int i;
};

#endif
