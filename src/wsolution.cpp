#include "wsolution.h"
#include <QIntValidator>
#include <QDoubleValidator>
#include <QtDebug>
#include <cmath>

WSolution::WSolution(QWidget *parent) : QWidget(parent)
{
    make();
    connections();
}

void WSolution::make()
{
    mLayout_.addWidget(&conditions_);
    this->setLayout(&mLayout_);
    makeConditions();
    makeOut();
}

void WSolution::makeConditions()
{
    fLayout_.addRow("Доля водорода H, %:", &eDh_); 
    fLayout_.addRow("Доля углерода C, %:", &eDc_);
    fLayout_.addRow("Вещество:", &cbSubstance_);
    fLayout_.addRow("Плотность, P:", &eDensity_);
    fLayout_.addRow("", &btnSolve_);
    conditions_.setLayout(&fLayout_);
    
    cbSubstance_.addItem("водород", QVariant(2));
    cbSubstance_.addItem("кислород", QVariant(32));
    cbSubstance_.addItem("воздух", QVariant(29));
    cbSubstance_.setCurrentIndex(1);
    
    eDh_.setText("25");
    eDc_.setText("75");

    eDensity_.setText("0,5");

    eDh_.setValidator(new QIntValidator(0, 100, this));
    eDc_.setValidator(new QIntValidator(0, 100, this));
    eDensity_.setValidator(new QDoubleValidator(0.0, 1000.0, 2, this));
}

void WSolution::makeOut()
{
    mLayout_.addWidget(&tOut_);
}

void WSolution::connections()
{
    connect(&eDc_, &QLineEdit::textChanged, this, &WSolution::reCountDh);
    connect(&eDh_, &QLineEdit::textChanged, this, &WSolution::reCountDc);
    connect(&eDc_, &QLineEdit::textEdited, this, &WSolution::dcLoseFocus);
    connect(&eDh_, &QLineEdit::textEdited, this, &WSolution::dhLoseFocus);
    connect(&btnSolve_, &QPushButton::clicked, this, &WSolution::solve);
}

void WSolution::reCountDc(const QString& text)
{
    int dh = text.toInt();
    int dc = 100 - dh;
    eDc_.setText(QString::number(dc));
}

void WSolution::reCountDh(const QString& text)
{
    int dc = text.toInt();
    int dh = 100 - dc;
    eDh_.setText(QString::number(dh));
}

void WSolution::dcLoseFocus()
{
    if (eDc_.text() == QString(""))
        eDc_.setText("0");
}

void WSolution::dhLoseFocus()
{
    if (eDh_.text() == QString(""))
        eDh_.setText("0");
}

void WSolution::solve()
{
    QString st;
    st = "1. Массовая доля водорода равна " + eDh_.text() + "%\n";
    st += "2. Составим соотношение долей веществ с их атомными массами: \n" +
        eDc_.text() + "/12 = " + eDh_.text() + "/1\n";

    double x = eDc_.text().toDouble() / 12;
    double y = eDh_.text().toDouble(); 

    if (x < y)
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

    st += "3. Разделив оба соотношения на наименьшее получим простейшую формулу " +
        sPartSub + "\n";

    double dM = cbSubstance_.currentData().toDouble();

    st += "4. Плотность по " + cbSubstance_.currentText() + "y " + "равна относительной " +
        "молекулярной массе всего вещества деленное на относительную молекулярную " +
        "массу " + cbSubstance_.currentText() + "а, а значит \n";
    st += "Р = M / 32, M = P * 32 = " + eDensity_.text() + " * " + QString::number(dM) + " = ";

    QString sM = eDensity_.text();
    sM.replace(',' , ".");
    double M = sM.toDouble() * dM;
    
    st += QString::number(M) + "\n";

    int Mpart = ix * 12 + iy;
    st += "5. Молекулярная масса простейшей формулы равна " + QString::number(x) + " * 12 + " +
        QString::number(iy) + " * 1 = " + QString::number(Mpart) + "\n";
        
    int k = std::ceil(M / Mpart);
    st += "6. k = M(вещества) / M(" + sPartSub + ")";
    st += " = " + QString::number(k) + "\n";
    st += "Искомая формула вещества С" + QString::number(ix * k) +
            "H" + QString::number(iy * k) + "\n";

    tOut_.setText(st);    
}

