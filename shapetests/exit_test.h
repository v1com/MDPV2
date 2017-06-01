#ifndef EXIT_TEST_H
#define EXIT_TEST_H


#include <QObject>

class Exit_Test : public QObject
{
    Q_OBJECT
public:
    explicit Exit_Test(QObject *parent = 0);

private slots:
    void getMyX();
    void getMyY();
    void setMyX();
    void setMyY();
};

#endif // EXIT_TEST_H
