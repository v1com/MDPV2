#ifndef CREATEDIAGRAMFORM_H
#define CREATEDIAGRAMFORM_H

#include "Scene.h"
#include "diagram.h"
#include "inputdialog.h"
#include "inputifdialog.h"

#include <QWidget>

#include <shapes/shape.h>
#include <shapes/arrow.h>

namespace Ui {
class CreateDiagramForm;
}

class CreateDiagramForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreateDiagramForm(QWidget *parent = 0);
    QList<Arrow*> arrows;
    ~CreateDiagramForm();

private slots:
    void on_blockButton_clicked();

    void on_ifBlockButton_clicked();

    void on_endBlockButton_clicked();

    void on_barButton_clicked();

    void on_startBlockButton_clicked();

    void on_clearSceneButton_clicked();

    void addArrow(Shape *to);
    void setArrowFrom(Shape *from);
    void repain();
    Shape* recur(Shape* s);
    Shape* returnStartBlock();
    void initDiargamOnScene(Diagram<Shape>*);
    void clearArrows();
    void on_saveButton_clicked();

    void on_loadButton_clicked();

private:
    Scene *myScene;
    int sceneCenterX;
    int sceneCenterY;
    Shape *arrowFrom = NULL;
    Diagram<Shape> *shapeContainer;
    Ui::CreateDiagramForm *ui;
};

#endif // CREATEDIAGRAMFORM_H
