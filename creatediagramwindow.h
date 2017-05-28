#ifndef CREATEDIAGRAMWINDOW_H
#define CREATEDIAGRAMWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QtWidgets>

namespace Ui {
class CreateDiagramWindow;
}

class CreateDiagramWindow : public QWidget {
    Q_OBJECT

public:
    explicit CreateDiagramWindow(QWidget *parent = 0);
    ~CreateDiagramWindow();

private:
    Ui::CreateDiagramWindow *ui;
};

#endif // CREATEDIAGRAMWINDOW_H
