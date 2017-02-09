#include "solver.h"
#include <cmath>

Solver::Solver(QObject *parent) : QObject(parent)
{

}

QString Solver::type1(double propH, double propC, double subM, double p)
{
    QString answer;

    answer = "1. Массовая доля водорода равна " + QString::number(propH) + "%\n";
    answer += "2. Составим соотношение долей веществ с их атомными массами: \n" +
        QString::number(propC) + "/12 = " + QString::number(propH) + "/1\n";

    double x = propC;
    double y = propH;

    if (propC < y)
    {
        y = y / x;
        x = 1.0;
    }
    else
    {
        x = x / y;
        y = 1.0;
    }

    int ix = std::ceil(x);
    int iy = std::ceil(y);

    QString sPartSub = "C" + QString::number(ix) + "H" + QString::number(iy);

    answer += "3. Разделив оба соотношения на наименьшее получим простейшую формулу " +
        sPartSub + "\n";

    QString nameSub;
    if (subM == 2.0)
        nameSub = "водород";
    else if (subM == 32)
        nameSub = "кислород";
    else if (subM == 29)
        nameSub = "воздух";

    answer += "4. Плотность по " + nameSub + "y " + "равна относительной " +
        "молекулярной массе всего вещества деленное на относительную молекулярную " +
        "массу " + nameSub + "а, а значит \n";
    answer += "P = M /" + QString::number(subM) + ", M = P * " + QString::number(subM);
    answer += " = " + QString::number(p) + " * " + QString::number(subM) + " = ";

    double M = p * subM;
    answer += QString::number(M) + "\n";

    return answer;
}
