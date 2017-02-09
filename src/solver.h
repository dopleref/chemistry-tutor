#ifndef SOLVER_H
#define SOLVER_H

#include <QObject>

class Solver : public QObject
{
    Q_OBJECT
public:
    explicit Solver(QObject *parent = 0);
    QString type1(double propH, double propC, double subM, double p);

signals:

public slots:

private:
    inline int min(int x, int y) { return (x < y) ? x : y; };
    inline double min(double x, double y) { return (x < y) ? x : y; };

};

#endif // SOLVER_H
