#include "exit_test.h"
#include <QtTest/QTest>

#include <shapes/exit.h>

Exit_Test::Exit_Test(QObject *parent) :
    QObject(parent)
{

}


void Exit_Test::getMyX() {
    Exit *exit = new Exit(10, 0);
    QCOMPARE(exit->getMyX(), 10);
    exit = new Exit(0, 0);
    QCOMPARE(exit->getMyX(), 0);
    delete exit;
}

void Exit_Test::getMyY() {
    Exit *exit = new Exit(0, 10);
    QCOMPARE(exit->getMyY(), 10);
    exit = new Exit(0, 0);
    QCOMPARE(exit->getMyY(), 0);
    delete exit;
}



void Exit_Test::setMyX() {
    Exit *exit = new Exit(0, 0);
    exit->setMyX(10);
    QCOMPARE(exit->getMyX(), 10);
    delete exit;
}

void Exit_Test::setMyY() {
    Exit *exit = new Exit(0, 0);
    exit->setMyY(10);
    QCOMPARE(exit->getMyY(), 10);
    delete exit;
}
