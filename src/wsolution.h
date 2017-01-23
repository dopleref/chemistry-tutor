#ifndef WSOLUTION_H
#define WSOLUTION_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QTextEdit>

class WSolution : public QWidget
{
    Q_OBJECT
public:
    explicit WSolution(QWidget *parent = 0);

public slots:
    void changeType(int typeNum);

signals:

public slots:

private:
    void make();
    void makeConditions1();
    void makeConditions2();
    void makeOut();
    void connections();
    
    void reCountDh(const QString& text);
    void reCountDc(const QString& text);
    void dhLoseFocus();
    void dcLoseFocus();

    void solve1();
    void solve2();

    QWidget conditions1_;
    QWidget conditions2_;

    QVBoxLayout mLayout_;

    QFormLayout fLayout1_;
    QFormLayout fLayout2_;
    /// интерфейс ввода входных данных для типа 1
    QLineEdit eDh_;
    QLineEdit eDc_;
    QComboBox cbSub1_;
    QLineEdit eDensity1_;
    QPushButton btnSolve1_ {"Решить"};
    /// интерфейс ввода входных данных для типа 2
    QLineEdit eMun_;
    QLineEdit eMco2_;
    QLineEdit eMh2o_;
    QComboBox cbSub2_;
    QLineEdit eDensity2_;
    QPushButton btnSolve2_ {"Решить"};

    QTextEdit tOut_;

};

#endif // WSOLUTION_H
