#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gaussianfilter.h"
#include "medianfilter.h"
#include "rgbchannels.h"
#include "saltpeppernoise.h"
#include "meanfilter.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "expand.h"
#include "decrease.h"
#include "gaussianoise.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
using namespace cv;
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    pageGaussianNoise = new GaussianNoisePage();
    pageGaussianNoise->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    pageSaltAndPepper = new SaltAndPepperNoisePage();
    pageSaltAndPepper->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    pageGaussianFilter = new GaussianFilterPage();
    pageGaussianFilter->show();
}

void MainWindow::on_pushButton_4_clicked()
{
        MedianFilter median_filter("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\Image_with_noise_salt_and_pepper.jpg");
        median_filter.applyFilter();
}

void MainWindow::on_pushButton_5_clicked()
{
        MeanFilter mean_filter("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\Image_with_noise_salt_and_pepper.jpg");
        mean_filter.applyFilter();
}

void MainWindow::on_pushButton_6_clicked()
{
        RGBChannels rgb("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg","red");
        rgb.applyFilter();
}

void MainWindow::on_pushButton_7_clicked()
{
    RGBChannels rgb("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg","blue");
    rgb.applyFilter();
}

void MainWindow::on_pushButton_8_clicked()
{
    RGBChannels rgb("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg","green");
    rgb.applyFilter();
}

void MainWindow::on_pushButton_9_clicked()
{
    pageDecrease = new DecreasePage();
    pageDecrease->show();
}

void MainWindow::on_pushButton_10_clicked()
{
    pageExpand = new ExpandPage();
    pageExpand->show();
}

