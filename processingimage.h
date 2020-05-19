#ifndef PROCESSINGIMAGE_H
#define PROCESSINGIMAGE_H
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;


class ProcessingImage
{
protected:
    string image_path;
    Mat image;
public:
    ProcessingImage(string path){
        this->image_path = path;
        this->setImage();
    }
    void setImage() {
        // Load an image
        image = imread(image_path, IMREAD_COLOR);

        if( !image.data )
        { exit(1); }
    }
};

#endif // PROCESSINGIMAGE_H
