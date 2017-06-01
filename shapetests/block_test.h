#ifndef BLOCK_TEST_H
#define BLOCK_TEST_H

#include <QObject>

class Block_Test : public QObject
{
    Q_OBJECT
public:
    explicit Block_Test(QObject *parent = 0);

private slots:
    void getMyX();
    void getMyY();
    void getWidth();
    void getHeight();
    void setMyX();
    void setMyY();
};

#endif // BLOCK_TEST_H
