#include "ifblock_test.h"
#include <QtTest/QTest>

#include <shapes/ifblock.h>

IfBlock_Test::IfBlock_Test(QObject *parent) :
    QObject(parent)
{

}


void IfBlock_Test::getMyX() {
    IfBlock *ifblock = new IfBlock(10, 0);
    QCOMPARE(ifblock->getMyX(), 10);
    ifblock = new IfBlock(0, 0);
    QCOMPARE(ifblock->getMyX(), 0);
    delete ifblock;
}

void IfBlock_Test::getMyY() {
    IfBlock *ifblock = new IfBlock(0, 10);
    QCOMPARE(ifblock->getMyY(), 10);
    ifblock = new IfBlock(0, 0);
    QCOMPARE(ifblock->getMyY(), 0);
    delete ifblock;
}



void IfBlock_Test::setMyX() {
    IfBlock *ifblock = new IfBlock(0, 0);
    ifblock->setMyX(10);
    QCOMPARE(ifblock->getMyX(), 10);
    delete ifblock;
}

void IfBlock_Test::setMyY() {
    IfBlock *ifblock = new IfBlock(0, 0);
    ifblock->setMyY(10);
    QCOMPARE(ifblock->getMyY(), 10);
    delete ifblock;
}
