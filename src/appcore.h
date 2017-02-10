#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <QFile>
#include "solver.h"

class AppCore : public QObject
{
    Q_OBJECT
public:
    explicit AppCore(QObject *parent = 0);
    Q_INVOKABLE QString getTheory1();
    Q_INVOKABLE void test(double value);
    Q_INVOKABLE QString type1(double propH, double propC, double subM, double p);

signals:
    void sendToQml(int count);
    void init();

public slots:
    void receiveFromQml();

private:
    int count;
    QString stheory1_;
    QFile file_ {":res/theory1.txt"};

    Solver solver_;

};

#endif // APPCORE_H
