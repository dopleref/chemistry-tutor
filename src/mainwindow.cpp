#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    make();
    connect(&cbType_, SIGNAL(currentIndexChanged(int)), &solution_, SLOT(changeType(int)));
}

MainWindow::~MainWindow()
{

}

void MainWindow::make()
{
    this->setMinimumHeight(800);
    this->setMinimumWidth(400);

    widget_.setLayout(&mLayout_);

    mLayout_.addWidget(&lType_, 0, Qt::AlignHCenter);
    mLayout_.addWidget(&cbType_, 0, Qt::AlignHCenter);
    mLayout_.addSpacing(50);
    mLayout_.addLayout(&tLayout_);
    mLayout_.addLayout(&bLayout_);
    bLayout_.addWidget(&tab_);

    lType_.setMinimumHeight(50);
    lType_.setMargin(20);
    cbType_.setMinimumHeight(100);

    tab_.addTab(&solution_, "Решение &1");
    tab_.addTab(&task_, "Задачи &2");
    tab_.addTab(&theory_, "Теория &3");

    cbType_.addItem("Тип 1: формула углеводорода", QVariant(0));
    cbType_.addItem("Тип 2: формула вещества", QVariant(1));

    QFont font("Arial", 18);
    widget_.setFont(font);

    setCentralWidget(&widget_);
}

void MainWindow::makeSolution()
{
}

void MainWindow::makeTask()
{
}

void MainWindow::makeTheory()
{
}

