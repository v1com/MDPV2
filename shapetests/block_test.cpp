#include "block_test.h"
#include <QtTest/QTest>

#include <shapes/block.h>

Block_Test::Block_Test(QObject *parent) :
    QObject(parent)
{

}

void Block_Test::getMyX() {
    Block *block = new Block(10, 0, 0, 0);
    QCOMPARE(block->getMyX(), 10);
    block = new Block(0, 0, 0 ,0);
    QCOMPARE(block->getMyX(), 0);
    delete block;
}

void Block_Test::getMyY() {
    Block *block = new Block(0, 10, 0, 0);
    QCOMPARE(block->getMyY(), 10);
    block = new Block(0, 0, 0 ,0);
    QCOMPARE(block->getMyY(), 0);
    delete block;
}

void Block_Test::getWidth() {
    Block *block = new Block(0, 0, 10, 0);
    QCOMPARE(block->getWidth(), 10);
    block = new Block(0, 0, 0 ,0);
    QCOMPARE(block->getWidth(), 0);
    delete block;
}

void Block_Test::getHeight() {
    Block *block = new Block(0, 0, 0, 10);
    QCOMPARE(block->getHeight(), 10);
    block = new Block(0, 0, 0 ,0);
    QCOMPARE(block->getHeight(), 0);
    delete block;
}

void Block_Test::setMyX() {
    Block *block = new Block(0, 0, 0, 0);
    block->setMyX(10);
    QCOMPARE(block->getMyX(), 10);
    delete block;
}

void Block_Test::setMyY() {
    Block *block = new Block(0, 0, 0, 0);
    block->setMyY(10);
    QCOMPARE(block->getMyY(), 10);
    delete block;
}
