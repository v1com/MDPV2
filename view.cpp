#include "View.h"
#include <QtDebug>

View::View(Scene * scene, int i) :
    QGraphicsView(scene),
    scene_(scene),
    i(i)
{

}
