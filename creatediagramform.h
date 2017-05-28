#ifndef CREATEDIAGRAMFORM_H
#define CREATEDIAGRAMFORM_H

#include <QWidget>

namespace Ui {
class CreateDiagramForm;
}

class CreateDiagramForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreateDiagramForm(QWidget *parent = 0);
    ~CreateDiagramForm();

private:
    Ui::CreateDiagramForm *ui;
};

#endif // CREATEDIAGRAMFORM_H
