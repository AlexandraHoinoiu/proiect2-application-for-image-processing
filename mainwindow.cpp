#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <vector>
#include <assert.h>
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

Matrix getGaussian(int height, int width, double sigma)
{
    Matrix kernel(height, Array(width));
    double sum=0.0;
    int i,j;

    for (i=0 ; i<height ; i++) {
        for (j=0 ; j<width ; j++) {
            kernel[i][j] = exp(-(i*i+j*j)/(2*sigma*sigma))/(2*M_PI*sigma*sigma);
            sum += kernel[i][j];
        }
    }

    for (i=0 ; i<height ; i++) {
        for (j=0 ; j<width ; j++) {
            kernel[i][j] /= sum;
        }
    }

    return kernel;
}

Image loadImage()
{
    cv::Mat image = cv::imread("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg", 1);
    imshow( "Original_image", image );
    Image imageMatrix(3, Matrix(image.rows, Array(image.cols)));
    for (int z = 0; z < image.channels(); z++)
        for (int i = 0; i < image.rows; i++)
          for (int j = 0; j < image.cols; j++){
            imageMatrix[z][i][j] = image.at<cv::Vec3f>(i,j)[z] ;
          }
    return imageMatrix;
}

void saveImage(Image &image, const char *filename)
{
    assert(image.size()==3);

    int height = image[0].size();
    int width = image[0][0].size();
    cv::Mat NewImage = cv::Mat(width, height, CV_8U);
    imshow( "Gaussian_image", NewImage );
    try {
           cv::imwrite(filename, NewImage);
       }
       catch (runtime_error& ex) {
           fprintf(stderr, "Exception converting image to PNG format: %s\n", ex.what());
           exit(1);
       }
}

Image applyFilter(Image &image, Matrix &filter){
    assert(image.size()==3 && filter.size()!=0);

    int height = image[0].size();
    int width = image[0][0].size();
    int filterHeight = filter.size();
    int filterWidth = filter[0].size();
    int newImageHeight = height-filterHeight+1;
    int newImageWidth = width-filterWidth+1;
    int d,i,j,h,w;

    Image newImage(3, Matrix(newImageHeight, Array(newImageWidth)));

    for (d=0 ; d<3 ; d++) {
        for (i=0 ; i<newImageHeight ; i++) {
            for (j=0 ; j<newImageWidth ; j++) {
                for (h=i ; h<i+filterHeight ; h++) {
                    for (w=j ; w<j+filterWidth ; w++) {
                        newImage[d][i][j] += filter[h-i][w-j]*image[d][h][w];
                    }
                }
            }
        }
    }

    return newImage;
}

Image applyFilter(Image &image, Matrix &filter, int times)
{
    Image newImage = image;
    for(int i=0 ; i<times ; i++) {
        newImage = applyFilter(newImage, filter);
    }
    return newImage;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Matrix filter = getGaussian(5, 5, 10.0);

    cout << "Loading image..." << endl;
    Image image = loadImage();
    cout << "Applying filter..." << endl;
    Image newImage = applyFilter(image, filter);
    cout << "Saving image..." << endl;
    saveImage(newImage, "newImage.png");
    cout << "Done!" << endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}

