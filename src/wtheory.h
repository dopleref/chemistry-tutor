#ifndef WTHEORY_H
#define WTHEORY_H

#include <QWidget>
#include <QTextEdit>
#include <QFile>
#include <QVBoxLayout>

class WTheory : public QWidget
{
    Q_OBJECT
public:
    explicit WTheory(QWidget *parent = 0);

signals:

public slots:

private:
    QVBoxLayout mLayout_;
    QTextEdit text_;
    QFile file_ {"theory1.txt"};
};

#endif // WTHEORY_H
