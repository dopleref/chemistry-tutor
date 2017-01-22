#include "wsolution.h"

WSolution::WSolution(QWidget *parent) : QWidget(parent)
{
    make();
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
    fLayout_.addRow("Доля водорода, Dh:", &eDh_);
    fLayout_.addRow("Доля углерода, Dc:", &eDc_);
    fLayout_.addRow("Вещество:", &cbSubstance_);
    fLayout_.addRow("Плотность:", &eDensity_);
    fLayout_.addRow("", &btnSolve_);
    conditions_.setLayout(&fLayout_);
    
    cbSubstance_.addItem("водород", QVariant(2));
    cbSubstance_.addItem("кислород", QVariant(32));
    cbSubstance_.addItem("воздух", QVariant(29));
    
    eDh_.setText("20 %");
    eDc_.setText("80 %");

    eDensity_.setText("1.00");
}

void WSolution::makeOut()
{
    mLayout_.addWidget(&tOut_);
}
