#include "wsolution.h"

WSolution::WSolution(QWidget *parent) : QWidget(parent)
{
    make();
}

void WSolution::make()
{
//    setLayout(&mLayout_);
//    mLayout_.addWidget(&conditions_);
//    mLayout_.addWidget(&out_);

    mLayout_.addWidget(&conditions_);
    this->setLayout(&mLayout_);
}

void WSolution::makeConditions()
{
//    conditions_.setLayout(&cLayout_);
//    cLayout_.addWidget(&lDh_, 0, 0);
//    cLayout_.addWidget(&eDh_, 0, 1);

    fLayout_.addRow("Доля водорода, Dh:", &eDh_);
    conditions_.setLayout(&fLayout_);
}

void WSolution::makeOut()
{

}
