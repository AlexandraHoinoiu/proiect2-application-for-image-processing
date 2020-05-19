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
    int radius = 9;
    double kernel[100][100];
    float sigma;

    public:
    GaussianFilter(string image_path, float sigma = 1.5):Filter(image_path){
        this->sigma = sigma;
    };

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
    int getColorValue (double color[100][100])
     {
         double sum = 0.0;
         for (int i=0 ; i<radius ; i++) {
             for (int j=0 ; j<radius ; j++) {
                 sum +=color[i][j];
             }

         }
         return int(sum);
     }
    void applyFilter()
    {
        Mat dst;
        image.copyTo(dst);
        this->getGaussian();
        int x,y,i,j;
        imshow( "Original_image", image );
         for (x=0 ; x<image.rows ; x++) {
             for (y=0 ; y<image.cols ; y++) {
                 double colorR[100][100];
                 double colorG[100][100];
                 double colorB[100][100];
                 for (i=0 ; i<radius; i++) {
                     for (j=0 ; j<radius ; j++) {
                         try {
                             int sampleX = x + i - (radius/2); // pozitia in imagine pe axa X
                             int sampleY = y + j - (radius/2); // pozitia in imagine pe axa Y
                             //inmultim numarul curent din kernel cu pixelul curent din imagine (pe fiecare canal)
                             colorR[i][j] = kernel[i][j] * image.at<Vec3b>(sampleX, sampleY)[0];
                             colorG[i][j] = kernel[i][j] * image.at<Vec3b>(sampleX, sampleY)[1];
                             colorB[i][j] = kernel[i][j] * image.at<Vec3b>(sampleX, sampleY)[2];

                         } catch (Exception e) {
                             cout<<e.msg;
                         }
                     }
                     //pixelul din imaginea noua va fi format din suma produselor dintre kernel si pixelii imaginii originale
                     /* pixelul rezultat va fi in mijlocul ferestreii =>
                      * daca fereastra este de 9 X 9 pixelul rezultat va fi pe pozitia (4,4)
                     */
                     dst.at<Vec3b>(x, y)[0] = getColorValue(colorR);
                     dst.at<Vec3b>(x, y)[1] = getColorValue(colorG);
                     dst.at<Vec3b>(x, y)[2] = getColorValue(colorB);
                 }
             }
         }
         imshow( "Gaussian_Filter_image", dst);

    }
};

#endif // GAUSSIANFILTER_H
