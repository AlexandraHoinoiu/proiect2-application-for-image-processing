#ifndef GAUSSIANOISE_H
#define GAUSSIANOISE_H
#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<noise.h>

using namespace std;
using namespace cv;

class GaussiaNoise: public Noise
{
    float sigma = 0.5;
    float mean = 0.5;

    double getModel(float z)
    {
        return -1*(sigma*sqrt(2*M_PI))*exp(-pow((z-mean),2)/(2*pow(sigma,2)));
    }

    public:
    GaussiaNoise(string path, float sigma = 1, float mean = 0.5):Noise(path)
    {
        this->sigma = sigma;
        this->mean = mean;
    }

    void applyNoise()
    {
        srand (time(NULL));
        Mat dst;
        float r = ((double) rand() / (RAND_MAX));
        float sign, value;
        image.copyTo(dst);
        float p[256], factor;
        imshow( "Original_image1", image );
        for(int i = 0; i < 256; i++) {
            p[i] = r - getModel(i);
        }
        factor = *min_element(p, p + 255);
        factor = factor*100;
          try
          {
              for(int i = 0; i < image.rows; i++) {
                  for(int j = 0; j < image.cols; j++) {
                      for(int k = 0; k < image.channels(); k++){
                           sign = (rand() % 2) * 2 - 1;
                           value =  dst.at<Vec3b>(i, j)[k] + sign * factor;
                           if( value < 0 ) {
                               dst.at<Vec3b>(i, j)[k] = 0;
                           } else if (value > 255) {
                               dst.at<Vec3b>(i, j)[k] = 255;
                           } else {
                               dst.at<Vec3b>(i, j)[k] = value;
                           }
                      }
                  }
               }
              imshow( "Image_Gaussian_noise", dst );
          }
          catch (Exception e)
          {
          cout<<e.msg;
          }
    }

};

#endif // GAUSSIANOISE_H
