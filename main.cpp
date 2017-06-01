#include "maindialog.h"
#include <QApplication>
#include <shapetests/block_test.h>
#include <QTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTest::qExec(new Block_Test, argc, argv);
    MainDialog w;
    w.show();

    return a.exec();
}
