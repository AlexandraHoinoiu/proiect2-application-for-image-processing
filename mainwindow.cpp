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
#include "resize.h"
#include "decrease.h"
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
    /*SaltPepperNoise noise_salt_pepper("C:\\Users\\Alex\\Desktop\\proiect 2\\proiect2-application-for-image-processing\\fruits.jpg");
    noise_salt_pepper.applyNoise(20);
    MedianFilter median_filter("C:\\Users\\Alex\\Desktop\\proiect 2\\proiect2-application-for-image-processing\\Image_with_noise_salt_and_pepper.jpg");
    median_filter.applyFilter();
    MeanFilter mean_filter("C:\\Users\\Alex\\Desktop\\proiect 2\\proiect2-application-for-image-processing\\Image_with_noise_salt_and_pepper.jpg");
    mean_filter.applyFilter();
    RGBChannels rgb("C:\\Users\\Alex\\Desktop\\proiect 2\\proiect2-application-for-image-processing\\fruits.jpg");
    rgb.get_R_Channel();
    rgb.get_G_Channel();
    rgb.get_B_Channel();
//    GaussianFilter gaussian_filter("C:\\Users\\Alex\\Desktop\\proiect 2\\proiect2-application-for-image-processing\\fruits.jpg");
//    gaussian_filter.applyFilter(5, 1.5);
*/
   // Resize resize ("C:\\Users\\Alex\\Desktop\\proiect 2\\proiect2-application-for-image-processing\\fruits.jpg",3);
 //   resize.resize();
    Decrease decrease("C:\\Users\\Alex\\Desktop\\proiect 2\\proiect2-application-for-image-processing\\fruits.jpg",3);
    decrease.decrease();
}

MainWindow::~MainWindow()
{
    delete ui;
}

