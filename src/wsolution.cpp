#include "wsolution.h"
#include <QIntValidator>
#include <QDoubleValidator>
#include <QtDebug>
#include <cmath>
#include <QDebug>

WSolution::WSolution(QWidget *parent) : QWidget(parent)
{
    make();
    connections();
}

void WSolution::changeType(int typeNum)
{
    if (typeNum == 0)
    {
        conditions1_.show();
        conditions2_.hide();
    }
    else
    {
        conditions2_.show();
        conditions1_.hide();
    }
    tOut_.clear();
}

void WSolution::make()
{
    mLayout_.addWidget(&conditions1_);
    mLayout_.addWidget(&conditions2_);
    this->setLayout(&mLayout_);
    makeConditions1();
    makeConditions2();
    makeOut();

    tOut_.setReadOnly(true);
    tOut_.setTextInteractionFlags(Qt::NoTextInteraction);
}

void WSolution::makeConditions1()
{
    fLayout1_.addRow("Доля водорода H, %:", &eDh_); 
    fLayout1_.addRow("Доля углерода C, %:", &eDc_);
    fLayout1_.addRow("Вещество:", &cbSub1_);
    fLayout1_.addRow("Плотность, P:", &eDensity1_);
    fLayout1_.addRow("", &btnSolve1_);
    conditions1_.setLayout(&fLayout1_);
    
    cbSub1_.addItem("водород", QVariant(2));
    cbSub1_.addItem("кислород", QVariant(32));
    cbSub1_.addItem("воздух", QVariant(29));
    cbSub1_.setCurrentIndex(1);
    
    eDh_.setText("25");
    eDc_.setText("75");

    eDensity1_.setText("0,5");

    eDh_.setValidator(new QIntValidator(0, 100, this));
    eDc_.setValidator(new QIntValidator(0, 100, this));
    eDensity1_.setValidator(new QDoubleValidator(0.0, 1000.0, 2, this));
}

void WSolution::makeConditions2()
{
    conditions2_.hide();
    conditions2_.setLayout(&fLayout2_);

    fLayout2_.addRow("m(вещества)", &eMun_);
    fLayout2_.addRow("m(CO2)", &eMco2_);
    fLayout2_.addRow("m(H2O)", &eMh2o_);
    fLayout2_.addRow("вещество", &cbSub2_);
    fLayout2_.addRow("плотность", &eDensity2_);
    fLayout2_.addRow("", &btnSolve2_);

    eMun_.setText("130");
    eMco2_.setText("44");
    eMh2o_.setText("18");
    cbSub2_.addItem("водород", QVariant(2));
    cbSub2_.setEnabled(false);
    eDensity2_.setText("39");

    eMun_.setValidator(new QDoubleValidator(0.0, 1000.0, 2, this));
    eMco2_.setValidator(new QDoubleValidator(0.0, 1000.0, 2, this));
    eMh2o_.setValidator(new QDoubleValidator(0.0, 1000.0, 2, this));
    eDensity2_.setValidator(new QDoubleValidator(0.0, 1000.0, 2, this));
}

void WSolution::makeOut()
{
    mLayout_.addWidget(&tOut_);
}

void WSolution::connections()
{
    connect(&eDc_, &QLineEdit::textChanged, this, &WSolution::reCountDh);
    connect(&eDh_, &QLineEdit::textChanged, this, &WSolution::reCountDc);
    connect(&eDc_, &QLineEdit::textEdited, this, &WSolution::dcLoseFocus);
    connect(&eDh_, &QLineEdit::textEdited, this, &WSolution::dhLoseFocus);
    connect(&btnSolve1_, &QPushButton::clicked, this, &WSolution::solve1);
    connect(&btnSolve2_, &QPushButton::clicked, this, &WSolution::solve2);
}

void WSolution::reCountDc(const QString& text)
{
    int dh = text.toInt();
    int dc = 100 - dh;
    eDc_.setText(QString::number(dc));
}

void WSolution::reCountDh(const QString& text)
{
    int dc = text.toInt();
    int dh = 100 - dc;
    eDh_.setText(QString::number(dh));
}

void WSolution::dcLoseFocus()
{
    if (eDc_.text() == QString(""))
        eDc_.setText("0");
}

void WSolution::dhLoseFocus()
{
    if (eDh_.text() == QString(""))
        eDh_.setText("0");
}

void WSolution::solve1()
{
    QString st;
    st = "1. Массовая доля водорода равна " + eDh_.text() + "%\n";
    st += "2. Составим соотношение долей веществ с их атомными массами: \n" +
        eDc_.text() + "/12 = " + eDh_.text() + "/1\n";

    double x = eDc_.text().toDouble() / 12;
    double y = eDh_.text().toDouble(); 

    if (x < y)
    {
        y = y / x;
        x = 1.0;
    }
    else
    {
        x = x / y;
        y = 1.0;
    }

    int ix = std::ceil(x);
    int iy = std::ceil(y);
    
    QString sPartSub = "C" + QString::number(ix) + "H" + QString::number(iy);

    st += "3. Разделив оба соотношения на наименьшее получим простейшую формулу " +
        sPartSub + "\n";

    double dM = cbSub1_.currentData().toDouble();

    st += "4. Плотность по " + cbSub1_.currentText() + "y " + "равна относительной " +
        "молекулярной массе всего вещества деленное на относительную молекулярную " +
        "массу " + cbSub1_.currentText() + "а, а значит \n";
    st += "Р = M / 32, M = P * 32 = " + eDensity1_.text() + " * " + QString::number(dM) + " = ";

    QString sM = eDensity1_.text();
    sM.replace(',' , ".");
    double M = sM.toDouble() * dM;
    
    st += QString::number(M) + "\n";

    int Mpart = ix * 12 + iy;
    st += "5. Молекулярная масса простейшей формулы равна " + QString::number(x) + " * 12 + " +
        QString::number(iy) + " * 1 = " + QString::number(Mpart) + "\n";
        
    int k = std::ceil(M / Mpart);
    st += "6. k = M(вещества) / M(" + sPartSub + ")";
    st += " = " + QString::number(k) + "\n";
    st += "Искомая формула вещества С" + QString::number(ix * k) +
            "H" + QString::number(iy * k) + "\n";

    tOut_.setText(st);    
}

void WSolution::solve2()
{
//    // найдем молекулярную массу вещества
//    double p = eDensity2_.text().toDouble();
//    double m_sub = p * 2.0;
//    // найдем массу углерода
//    double m_CO2 = eMco2_.text().toDouble();
//    double m_C = (12 * m_CO2) / 44;
//    // найдем массу водорода
//    double m_H2 = eMh2o_.text().toDouble();
//    double m_H = (2 * m_H2) / 18;
//    // определим наличие кислорода в веществе
//    double m_sum = m_C + m_H;
//    double m_un = eMun_.text().toDouble();
//    double m_O = m_un - m_sum;
//    // ветвление, в зависимости от наличия кислорода
//    double x, y, z;
//    int x1, x2, x3;
//    double min_val;
//    double m_simple;
//    int k;
//    if (m_O <= 0)
//    {
//        // если нету кислорода, то расчитываем вариант формулы CxHy
//        m_O = 0;
//        // составим формулу вещества
//        x = m_C / 12;
//        y = m_H;
//        min_val = std::fmin(x, y);
//        x = std::ceil(x / min_val);
//        y = std::ceil(y / min_val);
//        m_simple = x * 12 + y;
//        k = std::ceil(m_sub / m_simple);
//        x1 = int(x) * k;
//        x2 = int(y) * k;
//    }
//    else
//    {
//        // кислород присутствует, расчитываем вариант формулы CxHyOz
//        // составим формулу вещества
//        x = m_C / 12;
//        y = m_H;
//        z = m_O / 16;
//        min_val = std::fmin(std::fmin(x, y), z);
//        x = std::ceil(x / min_val);
//        y = std::ceil(y / min_val);
//        z = std::ceil(z / min_val);
//        m_simple = x * 12 + y + z * 16;
//        k = std::ceil(m_sub / m_simple);
//        x1 = int(x) * k;
//        x2 = int(y) * k;
//        x3 = int(z) * k;
//    }

//    // сформируем текст решения
//    tOut_.setText("");
//    QString text;
//    text = "1. Молекулярная масса вещества может быть вычислена по формуле\n";
//    text += "Mr = P * M(H2) = " + QString::number(p) + " * 2 = " +
//        QString::number(m_sub) + "\n";
//    text += "2. В 44 граммах СО2 содержится 12 граммов С.\n";
//    text += "Пусть в m(CO2) содержится x граммов C. Тогда мы можем составить ";
//    text += "пропорцию 44/12 = m(CO2)/m(C). \nОтсюда находим m(C) = (12 * m(CO2)) / 44 = ";
//    text += QString::number(m_C) + "\n";

//    text += "3. В 18 граммах H2O содержится 2 грамма H.\n";
//    text += "Пусть в m(H2O) содержится x граммов H. Тогда мы можем составить ";
//    text += "пропорцию 18/2 = m(H2O)/m(H). \nОтсюда находим m(H) = (2 * m(H2O)) / 18 = ";
//    text += QString::number(m_H) + "\n";

//    text += "4. Определим массу кислорода в веществе \nm(O) = m(вещества) - m(H) - m(C) = ";
//    text += QString::number(m_O);

//    if (m_O == 0)
//        text += " - в веществе кислород не содержится";
//    text += "\n";

//    if  (m_O != 0)
//    {
//        text += "5. Составим формулу вещества:\n";
//        text += "Для этого составим соотношение: m(C)/12 : m(H)/1 : m(O)/16 = " +
//        QString::number(x) + " : " + QString::number(y)  + " : " + QString::number(z) + "\n";
//        text += "Молекулярная масса простейшей формулы Mr = x * 12 + y +  z * 16 = ";
//        text += QString::number(m_simple) + "\n";
//        text += "Определим соотношение между молекулярной массой вещества и ";
//        text += "молекулярной массой простейшей формулы:\n";
//        text += "k = M(вещества) / M(простейшей формулы) = " + QString::number(k) + "\n";
//        text += "Искомое вещество - С" + QString::number(x1) +
//            "H" + QString::number(x2) + "O" + QString::number(x3) + "\n";
//    }
//    else
//    {
//        text += "5. Составим формулу вещества:\n";
//        text += "Для этого составим соотношение: m(C)/12 : m(H)/1 = " +
//        QString::number(x) + " : " + QString::number(y) + "\n";
//        text += "Молекулярная масса простейшей формулы Mr = x * 12 + y = ";
//        text += QString::number(m_simple) + "\n";
//        text += "Определим соотношение между молекулярной массой вещества и ";
//        text += "молекулярной массой простейшей формулы:\n";
//        text += "k = M(вещества) / M(простейшей формулы) = " + QString::number(k) + "\n";
//        text += "Искомое вещество - С" + QString::number(x1) +
//            "H" + QString::number(x2) + "\n";

//    }

//    tOut_.setText(text);

    tOut_.setText(QString("solution1"));
} 

