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

    QWidget conditions_;
    QWidget out_;

    QVBoxLayout mLayout_;

    QLabel lDh_ {"Доля водорода, Dh:"};
    QLabel lDc_ {"Доля водорода, Dс:"};
    QLabel lSubstance_ {"Вещество:"};
    QLabel lDensity_ {"Плотность:"};

    QGridLayout cLayout_;
    QLineEdit eDh_;
    QLineEdit eDc_;
    QComboBox cbSubstance_;
    QLineEdit eDensity_;

    QFormLayout fLayout_;

};

#endif // WSOLUTION_H
