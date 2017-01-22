#include "wtheory.h"
#include <QTextStream>
#include <QtDebug>
#include <QTextCodec>

WTheory::WTheory(QWidget *parent) : QWidget(parent)
{
    if (!file_.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "file not open";
        return;
    }

    QTextCodec* pCodec = QTextCodec::codecForName( "UTF-8");
    QTextStream in(&file_);
    in.setCodec(pCodec);
    QString line = in.readAll();
    text_.setText(line);

    mLayout_.addWidget(&text_);
    setLayout(&mLayout_);
}
