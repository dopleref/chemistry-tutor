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

signals:

public slots:

private:
    void make();
    void makeConditions();
    void makeOut();
    void connections();
    
    void reCountDh(const QString& text);
    void reCountDc(const QString& text);
    void dhLoseFocus();
    void dcLoseFocus();

    void solve();

    QWidget conditions_;
    QWidget out_;

    QVBoxLayout mLayout_;

    QFormLayout fLayout_;
    QLineEdit eDh_;
    QLineEdit eDc_;
    QComboBox cbSubstance_;
    QLineEdit eDensity_;
    QPushButton btnSolve_ {"Решить"};

    QTextEdit tOut_;
};

#endif // WSOLUTION_H
