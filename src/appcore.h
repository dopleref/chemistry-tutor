#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <QFile>

class AppCore : public QObject
{
    Q_OBJECT
public:
    explicit AppCore(QObject *parent = 0);
    Q_INVOKABLE QString getTheory1();

signals:
    void sendToQml(int count);
    void init();

public slots:
    void receiveFromQml();

private:
    int count;
    QString stheory1_;
    QFile file_ {":res/theory1.txt"};

};

#endif // APPCORE_H
