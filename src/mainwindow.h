#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>

#include "wsolution.h"
#include "wtask.h"
#include "wtheory.h"

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
    WSolution solution_;
    WTask task_;
    WTheory theory_;

};

#endif // MAINWINDOW_H
