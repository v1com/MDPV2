#ifndef CREATEDIAGRAMWINDOW_H
#define CREATEDIAGRAMWINDOW_H

#include <QMainWindow>

namespace Ui {
class CreateDiagramWindow;
}

class CreateDiagramWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateDiagramWindow(QWidget *parent = 0);
    ~CreateDiagramWindow();

private:
    Ui::CreateDiagramWindow *ui;
};

#endif // CREATEDIAGRAMWINDOW_H
