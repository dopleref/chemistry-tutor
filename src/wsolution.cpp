#include "wsolution.h"
#include <QIntValidator>
#include <QDoubleValidator>

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
    fLayout_.addRow("Доля водорода, %:", &eDh_); 
    fLayout_.addRow("Доля углерода, %:", &eDc_);
    fLayout_.addRow("Вещество:", &cbSubstance_);
    fLayout_.addRow("Плотность:", &eDensity_);
    fLayout_.addRow("", &btnSolve_);
    conditions_.setLayout(&fLayout_);
    
    cbSubstance_.addItem("водород", QVariant(2));
    cbSubstance_.addItem("кислород", QVariant(32));
    cbSubstance_.addItem("воздух", QVariant(29));
    
    eDh_.setText("20");
    eDc_.setText("80");

    eDensity_.setText("1,00");

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

    tOut_.setText(st);    
}

