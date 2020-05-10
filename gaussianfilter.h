#ifndef GAUSSIANFILTER_H
#define GAUSSIANFILTER_H
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include<cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <filter.h>
using namespace cv;
using namespace std;

class GaussianFilter : public Filter
{
private:
    int radius;
    double kernel[1000][1000];

    public:
    GaussianFilter(string image_path):Filter(image_path){};
    double getModel(double x, double y, double sigma)
    {
        return exp(-(x*x+y*y)/(2*sigma*sigma))/(2*M_PI*sigma*sigma);
    }

    void getGaussian(int radius, double sigma)
    {
        double sum=0.0;
        int i,j;
        for (i=0 ; i<radius ; i++) {
            for (j=0 ; j<radius ; j++) {
                kernel[i][j] = this->getModel(i-radius/2, j-radius/2, sigma);
                sum += kernel[i][j];
            }
        }

        for (i=0 ; i<radius ; i++) {
            for (j=0 ; j<radius ; j++) {
                kernel[i][j] /= sum;
            }
        }
    }
    int getColorValue (double color[1000][1000])
    {
        double sum = 0.0;
        for (int i=0 ; i<radius ; i++) {
            for (int j=0 ; j<radius ; j++) {
                sum +=color[i][j];
            }

        }
        return int(sum);
    }

    void applyFilter(int radius,  double sigma)
    {
        this->radius = radius;
        double kernel[radius][radius];
        Mat dst;
        double sum = 0.0;
        image.copyTo(dst);
        this->getGaussian(5,sigma);
        int x,y,i,j;
        imshow( "Original_image", image );
         for (x=0 ; x<image.cols ; x++) {
             for (y=0 ; y<image.rows ; y++) {
                 double colorR[radius][radius];
                 double colorG[radius][radius];
                 double colorB[radius][radius];
                 for (i=0 ; i<radius; i++) {
                     for (j=0 ; j<radius ; j++) {
                         try {
                             int sampleX = x + i - (radius/2);
                             int sampleY = y + j - (radius/2);
                             double curent = kernel[i][j];
                             double sampledColor[3];
                             sampledColor[0] = image.at<Vec3b>(sampleX, sampleY)[0];
                             sampledColor[1] = image.at<Vec3b>(sampleX, sampleY)[1];
                             sampledColor[2] = image.at<Vec3b>(sampleX, sampleY)[2];
                             colorR[i][j] = curent * sampledColor[0];
                             colorG[i][j] = curent * sampledColor[1];
                             colorB[i][j] = curent * sampledColor[2];
                             sum = 0.0;
                             for (int i=0 ; i<radius ; i++) {
                                 for (int j=0 ; j<radius ; j++) {
                                     sum +=colorR[i][j];
                                 }

                             }
                             dst.at<Vec3b>(y, x)[0] = int(sum);
                             sum = 0.0;
                             for (int i=0 ; i<radius ; i++) {
                                 for (int j=0 ; j<radius ; j++) {
                                     sum +=colorG[i][j];
                                 }

                             }
                             dst.at<Vec3b>(y, x)[1] = int(sum);
                             sum = 0.0;
                             for (int i=0 ; i<radius ; i++) {
                                 for (int j=0 ; j<radius ; j++) {
                                     sum +=colorR[i][j];
                                 }

                             }
                             dst.at<Vec3b>(y, x)[2] = int(sum);
                         } catch (Exception e) {
                             cout<<e.msg;
                         }
                     }
                 }
             }
         }
         imshow( "Gaussian_Filter_image", dst);
    }
};

#endif // GAUSSIANFILTER_H
