#include "wtask.h"
#include <QDebug>

WTask::WTask(QWidget *parent) : QWidget(parent)
{
    make();
    connections();
}

void WTask::make()
{
    mLayout_.addWidget(&btnGen_);
    mLayout_.addWidget(&out_);
    setLayout(&mLayout_);

    QString t1 = QString("Доля водорода 20 %, плотность по водороду 15, найти формулу вещества");
    QString t2 = QString("Доля углерода 80 %, плотность по водороду 1,034, найти формулу вещества");
    QString t3 = QString("Доля водорода 14 %, плотность по водороду 21, найти формулу вещества");

    tasks_.append(t1);
    tasks_.append(t2);
    tasks_.append(t3);
    out_.setText(tasks_[count_]);
}

void WTask::connections()
{
    connect(&btnGen_, &QPushButton::clicked, this, &WTask::gen);
}

void WTask::gen()
{
    count_++;
    if (count_ == 3)
        count_ = 0;

    out_.setText(tasks_[count_]);
}

