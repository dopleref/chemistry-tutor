#ifndef WTHEORY_H
#define WTHEORY_H

#include <QWidget>
#include <QTextEdit>

class WTheory : public QWidget
{
    Q_OBJECT
public:
    explicit WTheory(QWidget *parent = 0);

signals:

public slots:

private:
    QTextEdit text_;
    QString st_ {""};
};

#endif // WTHEORY_H
