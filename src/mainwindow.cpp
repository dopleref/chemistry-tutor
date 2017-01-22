#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    make();
}

MainWindow::~MainWindow()
{

}

void MainWindow::make()
{
    this->setFixedWidth(600);
    this->setFixedHeight(800);

    widget_.setLayout(&mLayout_);

    mLayout_.addLayout(&tLayout_);
    mLayout_.addLayout(&bLayout_);
    bLayout_.addWidget(&tab_);
    tab_.setFixedHeight(680);

    tab_.addTab(&solution_, "Решение &1");
    tab_.addTab(&task_, "Задачи &2");
    tab_.addTab(&theory_, "Теория &3");

    tLayout_.addWidget(&lType_);
    tLayout_.addWidget(&cbType_);

    cbType_.addItem("Тип 1: молекулярная формула углеводорода", QVariant(0));
    cbType_.addItem("Тип 2: молекулярная формула вещества", QVariant(1));

    QFont font("Arial", 12);
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

