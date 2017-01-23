#include "wsolution.h"
#include <QIntValidator>
#include <QDoubleValidator>
#include <QtDebug>
#include <cmath>
#include <QDebug>

WSolution::WSolution(QWidget *parent) : QWidget(parent)
{
    make();
    connections();
}

void WSolution::changeType(int typeNum)
{
    if (typeNum == 0)
    {
        conditions1_.show();
        conditions2_.hide();
    }
    else
    {
        conditions2_.show();
        conditions1_.hide();
    }
    tOut_.clear();
}

void WSolution::make()
{
    mLayout_.addWidget(&conditions1_);
    mLayout_.addWidget(&conditions2_);
    this->setLayout(&mLayout_);
    makeConditions1();
    makeConditions2();
    makeOut();
}

void WSolution::makeConditions1()
{
    fLayout1_.addRow("Доля водорода H, %:", &eDh_); 
    fLayout1_.addRow("Доля углерода C, %:", &eDc_);
    fLayout1_.addRow("Вещество:", &cbSub1_);
    fLayout1_.addRow("Плотность, P:", &eDensity1_);
    fLayout1_.addRow("", &btnSolve1_);
    conditions1_.setLayout(&fLayout1_);
    
    cbSub1_.addItem("водород", QVariant(2));
    cbSub1_.addItem("кислород", QVariant(32));
    cbSub1_.addItem("воздух", QVariant(29));
    cbSub1_.setCurrentIndex(1);
    
    eDh_.setText("25");
    eDc_.setText("75");

    eDensity1_.setText("0,5");

    eDh_.setValidator(new QIntValidator(0, 100, this));
    eDc_.setValidator(new QIntValidator(0, 100, this));
    eDensity1_.setValidator(new QDoubleValidator(0.0, 1000.0, 2, this));
}

void WSolution::makeConditions2()
{
    conditions2_.hide();
    conditions2_.setLayout(&fLayout2_);

    fLayout2_.addRow("m(вещества)", &eMun_);
    fLayout2_.addRow("m(CO2)", &eMco2_);
    fLayout2_.addRow("m(H2O)", &eMh2o_);
    fLayout2_.addRow("вещество", &cbSub2_);
    fLayout2_.addRow("плотность по H2", &eDensity2_);
    fLayout2_.addRow("", &btnSolve2_);

    eMco2_.setText("44");
    eMh2o_.setText("18");
    cbSub2_.addItem("водород", QVariant(2));
    cbSub2_.setEnabled(false);

    eMun_.setValidator(new QDoubleValidator(0.0, 1000.0, 2, this));
    eMco2_.setValidator(new QDoubleValidator(0.0, 1000.0, 2, this));
    eMh2o_.setValidator(new QDoubleValidator(0.0, 1000.0, 2, this));
    eDensity2_.setValidator(new QDoubleValidator(0.0, 1000.0, 2, this));
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
    connect(&btnSolve1_, &QPushButton::clicked, this, &WSolution::solve);
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

    double dM = cbSub1_.currentData().toDouble();

    st += "4. Плотность по " + cbSub1_.currentText() + "y " + "равна относительной " +
        "молекулярной массе всего вещества деленное на относительную молекулярную " +
        "массу " + cbSub1_.currentText() + "а, а значит \n";
    st += "Р = M / 32, M = P * 32 = " + eDensity1_.text() + " * " + QString::number(dM) + " = ";

    QString sM = eDensity1_.text();
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

