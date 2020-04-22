#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H
#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

class MedianFilter
{
    string image_path;
    Mat image;
public:
    MedianFilter(string path)
    {
        image_path = path;
        setImage();
    }

    void setImage() {
        // Load an image
        image = imread(image_path, IMREAD_GRAYSCALE);

        if( !image.data )
        { exit(1); }
    }
    void insertionSort(int window[])
    {
        int temp, i , j;
        for(i = 0; i < 9; i++){
            temp = window[i];
            for(j = i-1; j >= 0 && temp < window[j]; j--){
                window[j+1] = window[j];
            }
            window[j+1] = temp;
        }
    }

    Mat applyFilter()
    {
        Mat image, dst;

              //create a sliding window of size 9
              int window[9];

                dst = image.clone();
                for(int y = 0; y < image.rows; y++)
                    for(int x = 0; x < image.cols; x++)
                        dst.at<uchar>(y,x) = 0.0;

                for(int y = 1; y < image.rows - 1; y++){
                    for(int x = 1; x < image.cols - 1; x++){

                        // Pick up window element

                        window[0] = image.at<uchar>(y - 1 ,x - 1);
                        window[1] = image.at<uchar>(y, x - 1);
                        window[2] = image.at<uchar>(y + 1, x - 1);
                        window[3] = image.at<uchar>(y - 1, x);
                        window[4] = image.at<uchar>(y, x);
                        window[5] = image.at<uchar>(y + 1, x);
                        window[6] = image.at<uchar>(y - 1, x + 1);
                        window[7] = image.at<uchar>(y, x + 1);
                        window[8] = image.at<uchar>(y + 1, x + 1);

                        // sort the window to find median
                        insertionSort(window);

                        // assign the median to centered element of the matrix
                        dst.at<uchar>(y,x) = window[4];
                    }
                }
    }


};

#endif // MEDIANFILTER_H
