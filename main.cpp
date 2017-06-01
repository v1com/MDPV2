#include "maindialog.h"
#include <QApplication>
#include <shapetests/bar_test.h>
#include <shapetests/block_test.h>
#include <shapetests/entrance_test.h>
#include <shapetests/exit_test.h>
#include <shapetests/ifblock_test.h>
#include <QTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTest::qExec(new Block_Test, argc, argv);
        QTest::qExec(new Bar_Test, argc, argv);
            QTest::qExec(new Entrance_Test, argc, argv);
                QTest::qExec(new Exit_Test, argc, argv);
                    QTest::qExec(new IfBlock_Test, argc, argv);

    MainDialog w;
    w.show();

    return a.exec();
}

