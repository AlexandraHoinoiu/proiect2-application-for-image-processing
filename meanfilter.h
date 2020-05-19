#ifndef MEANFILTER_H
#define MEANFILTER_H
#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <filter.h>
using namespace std;
using namespace cv;


class MeanFilter: public Filter
{
    float mean(int arr[])
        {
            int i, avr = 0;
            for (i = 1; i < 9; i++)
            {
                avr += arr[i];
            }
            return avr/9;
        }
public:
    MeanFilter(string image_path):Filter(image_path){};
        void applyFilter()
        {
            Mat dst;
            image.copyTo(dst);
            int window[9];
            imshow( "Original_image3", image );
              try
              {
                  for(int i = 1; i < image.rows - 1; i++) {
                      for(int j = 1; j < image.cols - 1; j++) {
                          for(int k = 0; k < 3; k++) {
                               window[0] = int(image.at<Vec3b>(i-1, j-1)[k]);
                               window[1] = int(image.at<Vec3b>(i-1, j)[k]);
                               window[2] = int(image.at<Vec3b>(i-1, j+1)[k]);
                               window[3] = int(image.at<Vec3b>(i, j-1)[k]);
                               window[4] = int(image.at<Vec3b>(i, j)[k]);
                               window[5] = int(image.at<Vec3b>(i, j+1)[k]);
                               window[6] = int(image.at<Vec3b>(i+1, j-1)[k]);
                               window[7] = int(image.at<Vec3b>(i+1, j)[k]);
                               window[8] = int(image.at<Vec3b>(i+1, j+1)[k]);
                                dst.at<Vec3b>(i, j)[k] =  this->mean(window);
                          }
                      }
                  }
                  imshow( "Mean_filter_image", dst );
              }
              catch (Exception e)
              {
              cout<<e.msg;
              }
        }
    };

    #endif // MEANFILTER_H
