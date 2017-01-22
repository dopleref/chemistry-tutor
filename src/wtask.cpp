#include "wtask.h"

WTask::WTask(QWidget *parent) : QWidget(parent)
{
    make();
}

void WTask::make()
{
    mLayout_.addWidget(&btnGen_);
    mLayout_.addWidget(&out_);
    setLayout(&mLayout_);
}

void WTask::connections()
{
}

