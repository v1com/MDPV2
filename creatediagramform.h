#ifndef CREATEDIAGRAMFORM_H
#define CREATEDIAGRAMFORM_H

#include "Scene.h"
#include "diagram.h"

#include <QWidget>

#include <shapes/shape.h>

namespace Ui {
class CreateDiagramForm;
}

class CreateDiagramForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreateDiagramForm(QWidget *parent = 0);
    ~CreateDiagramForm();

private slots:
    void on_blockButton_clicked();

    void on_ifBlockButton_clicked();

    void on_endBlockButton_clicked();

    void on_barButton_clicked();

    void on_startBlockButton_clicked();

    void on_clearSceneButton_clicked();

private:
    Scene *myScene;
    int sceneCenterX;
    int sceneCenterY;
    Diagram<Shape> *shapeContainer;
    Ui::CreateDiagramForm *ui;
};

#endif // CREATEDIAGRAMFORM_H
