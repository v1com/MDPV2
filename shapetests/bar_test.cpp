#include "bar_test.h"
#include <QtTest/QTest>

#include <shapes/bar.h>

Bar_Test::Bar_Test(QObject *parent) :
    QObject(parent)
{

}

void Bar_Test::getMyX() {
    Bar *bar = new Bar(10, 0);
    QCOMPARE(bar->getMyX(), 10);
    bar = new Bar(0, 0);
    QCOMPARE(bar->getMyX(), 0);
    delete bar;
}

void Bar_Test::getMyY() {
    Bar *bar = new Bar(0, 10);
    QCOMPARE(bar->getMyY(), 10);
    bar = new Bar(0, 0);
    QCOMPARE(bar->getMyY(), 0);
    delete bar;
}



void Bar_Test::setMyX() {
    Bar *bar = new Bar(0, 0);
    bar->setMyX(10);
    QCOMPARE(bar->getMyX(), 10);
    delete bar;
}

void Bar_Test::setMyY() {
    Bar *bar = new Bar(0, 0);
    bar->setMyY(10);
    QCOMPARE(bar->getMyY(), 10);
    delete bar;
}
