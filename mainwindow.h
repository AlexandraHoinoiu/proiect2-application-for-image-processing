#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gaussianfilterpage.h"
#include "gaussiannoisepage.h"
#include "decreasepage.h"
#include "expandpage.h"
#include "saltandpeppernoisepage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_stackedWidget_currentChanged(int arg1);

private:
    Ui::MainWindow *ui;
    GaussianFilterPage *pageGaussianFilter;
    GaussianNoisePage *pageGaussianNoise;
    SaltAndPepperNoisePage *pageSaltAndPepper;
    DecreasePage *pageDecrease;
    ExpandPage *pageExpand;

};
#endif // MAINWINDOW_H
