#ifndef IFBLOCK_TEST_H
#define IFBLOCK_TEST_H

#include <QObject>

class IfBlock_Test : public QObject
{
    Q_OBJECT
public:
    explicit IfBlock_Test(QObject *parent = 0);

private slots:
    void getMyX();
    void getMyY();
    void setMyX();
    void setMyY();
};

#endif // IFBLOCK_TEST_H
