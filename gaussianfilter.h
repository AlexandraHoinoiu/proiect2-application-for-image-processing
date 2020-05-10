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
    int radius = 3;
    double kernel[1000][1000];
    float sigma = 1.5;

    public:
    GaussianFilter(string image_path):Filter(image_path){};

    double getModel(double x, double y)
    {
        return exp(-(x*x+y*y)/(2*sigma*sigma))/(2*M_PI*sigma*sigma);
    }

    void getGaussian()
    {
        double sum=0.0;
        int i,j;
        for (i=0 ; i<radius ; i++) {
            for (j=0 ; j<radius ; j++) {
                kernel[i][j] = this->getModel(i-radius/2, j-radius/2);
                sum += kernel[i][j];
            }
        }

        for (i=0 ; i<radius ; i++) {
            for (j=0 ; j<radius ; j++) {
                kernel[i][j] /= sum;
            }
        }
    }
    void applyFilter()
    {
        Mat dst;
//        image.copyTo(dst);
//        this->getGaussian();
//        int x,y,k,i,j,step=radius/2;;
//        float sum;
        imshow( "Original_image", image );
//         for (x=1 ; x<image.cols-1 ; x++) {
//             for (y=1 ; y<image.rows-1 ; y++) {
//                 for(k=0; k< 3; k++) { // for each channel
//                     sum = 0;
//                     for(i=x-step; i<x+step; i++){
//                         for(j = y-step; j<y+step; j++) {
//                             sum += image.at<Vec3b>(i, j)[k];
//                         }
//                     }
//                     cout<<sum;
//                     dst.at<Vec3b>(x, y)[k] = sum;
//                 }
//             }
//         }
//         imshow( "Gaussian_Filter_image", dst);
    }
};

#endif // GAUSSIANFILTER_H
