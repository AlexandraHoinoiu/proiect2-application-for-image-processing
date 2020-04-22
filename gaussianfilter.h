#ifndef GAUSSIANFILTER_H
#define GAUSSIANFILTER_H
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

class GaussianFilter
{
    typedef vector<double> Array;
    typedef vector<Array> Matrix;
    typedef vector<Matrix> Image;
    string image_path;
    Mat image;

    public:
    GaussianFilter(string path)
    {
        image_path = path;
        setImage();
    }
    void setImagePath(string path)
    {
        image_path = path;
    }
    void setImage() {
        // Load an image
        image = imread(image_path, IMREAD_COLOR);

        if( !image.data )
        { exit(1); }
    }

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

    void applyFilter(Matrix &filter)
    {
        int height = image.cols;
        int width = image.rows;
        int filterHeight = filter.size();
        int filterWidth = filter[0].size();
        int newImageHeight = height-filterHeight+1;
        int newImageWidth = width-filterWidth+1;
        Mat newImage(cv::Size(newImageHeight,newImageWidth), CV_32FC(3));
        imshow( "Original_image", image );
        int d,i,j,h,w;
        for (d = 0; d < image.channels(); d++) {
            for (i=0 ; i<newImageHeight ; i++) {
                for (j=0 ; j<newImageWidth ; j++) {
                    for (h=i ; h<i+filterHeight ; h++) {
                        for (w=j ; w<j+filterWidth ; w++) {
                            Vec3b &intensityNewImage = newImage.at<Vec3b>(j, i);
                            Vec3b intensityImage = image.at<Vec3b>(h, w);
                            cout<<intensityImage<<" ";
//                             intensityNewImage.val[d] = intensityImage.val[d];
                        }
                    }
                }
            }

        }
        imshow( "Gaussian_image", newImage );
    }
};

#endif // GAUSSIANFILTER_H
