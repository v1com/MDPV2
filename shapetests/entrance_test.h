#ifndef ENTRANCE_TEST_H
#define ENTRANCE_TEST_H

#include <QObject>

class Entrance_Test : public QObject
{
    Q_OBJECT
public:
    explicit Entrance_Test(QObject *parent = 0);

private slots:
    void getMyX();
    void getMyY();
    void setMyX();
    void setMyY();
};

#endif // ENTRANCE_TEST_H
