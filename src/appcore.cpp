#include "appcore.h"

#include <QTextStream>
#include <QtDebug>
#include <QTextCodec>

AppCore::AppCore(QObject *parent) : QObject(parent)
{
    count = 0;
    if (!file_.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "file not open";
        return;
    }

    QTextCodec* pCodec = QTextCodec::codecForName( "UTF-8");
    QTextStream in(&file_);
    in.setCodec(pCodec);
    stheory1_ = in.readAll();

    file_.close();
}

QString AppCore::getTheory1()
{
    return stheory1_;
}

void AppCore::test(double value)
{
    qDebug() << "test!" << value;
}

QString AppCore::type1(double propH, double propC, double subM, double p)
{
    return solver_.type1(propH, propC, subM, p);
}

void AppCore::receiveFromQml()
{
    count++;
    emit  sendToQml(count);
}
