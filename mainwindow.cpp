#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gaussianfilter.h"
#include "medianfilter.h"
#include "rgbchannels.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
using namespace cv;
using namespace std;

typedef vector<double> Array;
typedef vector<Array> Matrix;
typedef vector<Matrix> Image;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GaussianFilter gaussian("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg");
    Matrix filter = gaussian.getGaussian(5,5,10.0);
    gaussian.applyFilter(filter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

