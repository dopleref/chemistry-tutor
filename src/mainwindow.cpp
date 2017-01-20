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
    this->setFixedWidth(500);
    this->setFixedHeight(700);

    this->layout()->addWidget(&tab_);
    tab_.setFixedHeight(680);

    tab_.addTab(&solution_, "Решение");
    tab_.addTab(&task_, "Задачи");
    tab_.addTab(&theory_, "Теория");
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

