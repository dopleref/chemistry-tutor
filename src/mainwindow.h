#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void make();
    void makeSolution();
    void makeTask();
    void makeTheory();

    QTabWidget tab_;
    QWidget solution_;
    QWidget task_;
    QWidget theory_;

};

#endif // MAINWINDOW_H
