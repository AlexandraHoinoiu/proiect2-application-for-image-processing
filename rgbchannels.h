#ifndef RGBCHANNELS_H
#define RGBCHANNELS_H
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

class RGBChannels
{
    string image_path;
    Mat image,zero;
public:
    RGBChannels(string path)
    {
        this->image_path = path;
        this->setImage();
        this->setZero();
    }
    void setImage()
    {
        // Load an image
        this->image = imread(image_path, IMREAD_COLOR);

        if( !image.data )
        { exit(1); }
    }
    void setZero()
    {
        zero = Mat::zeros(Size(image.cols, image.rows), CV_8UC1);
    }
    void get_R_Channel()
    {
        Mat red_image;
        vector<Mat> rgbChannels(3);
        split(image, rgbChannels);
        vector<Mat> channels;
        channels.push_back(zero);
        channels.push_back(zero);
        channels.push_back(rgbChannels[2]);

       /// Merge the three channels
       merge(channels, red_image);
       imshow("Red", red_image);
    }
    void get_G_Channel()
    {
        Mat green_image;
        vector<Mat> rgbChannels(3);
        split(image, rgbChannels);
        vector<Mat> channels;
        channels.push_back(zero);
        channels.push_back(rgbChannels[1]);
        channels.push_back(zero);
        merge(channels, green_image);
        imshow("Green", green_image);
    }
    void get_B_Channel()
    {
        Mat blue_image;
        vector<Mat> rgbChannels(3);
        split(image, rgbChannels);
        vector<Mat> channels;
        channels.push_back(rgbChannels[0]);
        channels.push_back(zero);
        channels.push_back(zero);
        merge(channels, blue_image);
        imshow("Blue", blue_image);
    }
};

#endif // RGBCHANNELS_H
