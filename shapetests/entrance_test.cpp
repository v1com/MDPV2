#include "entrance_test.h"
#include <QtTest/QTest>

#include <shapes/entrance.h>

Entrance_Test::Entrance_Test(QObject *parent) :
    QObject(parent)
{

}

void Entrance_Test::getMyX() {
    Entrance *entrance = new Entrance(10, 0);
    QCOMPARE(entrance->getMyX(), 10);
    entrance = new Entrance(0, 0);
    QCOMPARE(entrance->getMyX(), 0);
    delete entrance;
}

void Entrance_Test::getMyY() {
    Entrance *entrance = new Entrance(0, 10);
    QCOMPARE(entrance->getMyY(), 10);
    entrance = new Entrance(0, 0);
    QCOMPARE(entrance->getMyY(), 0);
    delete entrance;
}



void Entrance_Test::setMyX() {
    Entrance *entrance = new Entrance(0, 0);
    entrance->setMyX(10);
    QCOMPARE(entrance->getMyX(), 10);
    delete entrance;
}

void Entrance_Test::setMyY() {
    Entrance *entrance = new Entrance(0, 0);
    entrance->setMyY(10);
    QCOMPARE(entrance->getMyY(), 10);
    delete entrance;
}
