#ifndef FILTER_H
#define FILTER_H
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <processingimage.h>

using namespace cv;
using namespace std;

class Filter : public ProcessingImage
{
public:
    Filter(string path):ProcessingImage(path){};
    virtual void applyFilter() = 0;
};

#endif // FILTER_H
