#ifndef BAR_TEST_H
#define BAR_TEST_H

#include <QObject>

class Bar_Test : public QObject
{
    Q_OBJECT
public:
    explicit Bar_Test(QObject *parent = 0);

private slots:
    void getMyX();
    void getMyY();
    void setMyX();
    void setMyY();
};


#endif // BAR_TEST_H
