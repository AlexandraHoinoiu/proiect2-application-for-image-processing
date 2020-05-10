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
//    SaltPepperNoise noise_salt_pepper("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg");
//    noise_salt_pepper.applyNoise(20);
//    MedianFilter median_filter("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\Image_with_noise_salt_and_pepper.jpg");
//    median_filter.applyFilter();
//    MeanFilter mean_filter("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\Image_with_noise_salt_and_pepper.jpg");
//    mean_filter.applyFilter();
//    RGBChannels rgb("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg");
//    rgb.get_R_Channel();
//    rgb.get_G_Channel();
//    rgb.get_B_Channel();
    GaussianFilter gaussian_filter("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg");
    gaussian_filter.applyFilter();


}

MainWindow::~MainWindow()
{
    delete ui;
}

