#ifndef NOISE_H
#define NOISE_H
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <processingimage.h>

class Noise : public ProcessingImage
{
public:
    Noise(string path):ProcessingImage(path){};
    virtual void applyNoise() = 0;
};

#endif // NOISE_H
