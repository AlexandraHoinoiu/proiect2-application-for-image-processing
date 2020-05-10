#ifndef FILTER_H
#define FILTER_H
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
using namespace cv;
using namespace std;


class Filter
{
protected:
    string image_path;
    Mat image;
public:
    Filter(string path){
        this->image_path = path;
        this->setImage();
    }
    void setImage() {
        // Load an image
        image = imread(image_path, IMREAD_COLOR);

        if( !image.data )
        { exit(1); }
    }
    virtual void applyFilter() = 0;
};

#endif // FILTER_H
