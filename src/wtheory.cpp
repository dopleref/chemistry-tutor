#include "wtheory.h"
#include <QTextStream>
#include <QtDebug>

WTheory::WTheory(QWidget *parent) : QWidget(parent)
{
    if (!file_.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "file not open";
        return;
    }

    QTextStream in(&file_);
    QString line = in.readAll();
    text_.setText(line);

    mLayout_.addWidget(&text_);
    setLayout(&mLayout_);
}
