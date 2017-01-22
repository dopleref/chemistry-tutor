#ifndef WTASK_H
#define WTASK_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>

class WTask : public QWidget
{
    Q_OBJECT
public:
    explicit WTask(QWidget *parent = 0);

signals:

public slots:

private:
    void make();
    void connections();

    void gen();

    QVBoxLayout mLayout_;
    QPushButton btnGen_ {"Сгенерировать задачу"};
    QTextEdit out_;
    
    int count_ = 0;
    QList<QString> tasks_;
};

#endif // WTASK_H
