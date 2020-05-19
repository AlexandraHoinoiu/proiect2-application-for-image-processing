#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H
#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <filter.h>

using namespace std;
using namespace cv;

class MedianFilter:public Filter
{
    void insertionSort(int arr[])
    {
        int i, key, j;
        for (i = 1; i < 9; i++)
        {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
public:
    MedianFilter(string image_path):Filter(image_path){};
    void applyFilter()
    {
        Mat dst;
        image.copyTo(dst);
        int window[9];
        imshow( "Original_image2", image );
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
                           this->insertionSort(window);
                            dst.at<Vec3b>(i, j)[k] = window[4];
                      }
                  }
              }
              imshow( "Median_filter_image", dst );
          }
          catch (Exception e)
          {
          cout<<e.msg;
          }
    }

};
#endif // MEDIANFILTER_H
