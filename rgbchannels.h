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
#include <filter.h>

using namespace cv;
using namespace std;

class RGBChannels  : public Filter
{
    string channel;
    Mat zero;

    void get_R_Channel()
    {
        imshow("Image_with_3_channels", image);
        Mat red_image;
        vector<Mat> rgbChannels(3);
        split(image, rgbChannels);
        vector<Mat> channels;
        channels.push_back(zero);
        channels.push_back(zero);
        channels.push_back(rgbChannels[2]);

       /// Merge the three channels
       merge(channels, red_image);
       imshow("Red_channel", red_image);
    }
    void get_G_Channel()
    {
        imshow("Image_with_3_channels", image);
        Mat green_image;
        vector<Mat> rgbChannels(3);
        split(image, rgbChannels);
        vector<Mat> channels;
        channels.push_back(zero);
        channels.push_back(rgbChannels[1]);
        channels.push_back(zero);
        merge(channels, green_image);
        imshow("Green_channel", green_image);
    }
    void get_B_Channel()
    {
        imshow("Image_with_3_channels", image);
        Mat blue_image;
        vector<Mat> rgbChannels(3);
        split(image, rgbChannels);
        vector<Mat> channels;
        channels.push_back(rgbChannels[0]);
        channels.push_back(zero);
        channels.push_back(zero);
        merge(channels, blue_image);
        imshow("Blue_channel", blue_image);
    }
    void setZero()
    {
        zero = Mat::zeros(Size(image.cols, image.rows), CV_8UC1);
    }
public:
    RGBChannels(string image_path, string channel):Filter(image_path){
        this->channel = channel;
        this->setZero();
    }
    void applyFilter() {
        if(this->channel == "red") {
            this->get_R_Channel();
        } else if (this->channel == "green") {
            this->get_G_Channel();
        } else if (this->channel == "blue") {
            this->get_B_Channel();
        } else {
            cout<<"You can chooise only 'red', 'green' or 'blue' color !";
        }
    }
};

#endif // RGBCHANNELS_H
