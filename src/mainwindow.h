#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>

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

    QWidget widget_;

    QVBoxLayout mLayout_;
    QHBoxLayout tLayout_;
    QVBoxLayout bLayout_;
    QLabel lType_ {"Выберите тип задачи:"};
    QComboBox cbType_;

    QTabWidget tab_;
    QWidget solution_;
    QWidget task_;
    QWidget theory_;

};

#endif // MAINWINDOW_H
