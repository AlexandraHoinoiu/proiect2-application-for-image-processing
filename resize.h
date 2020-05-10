#ifndef RESIZE_H
#define RESIZE_H
#include <iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

class Resize
{
private:
    string image_path;
    Mat image;
public:
    Resize(string path)
    {
        this->image_path = path;
        this->setImage();
    }
    void setImage()
    {
        // Load an image
        this->image = imread(image_path, IMREAD_COLOR);

        if( !image.data )
        { exit(1); }
    }
    /*void resize(){
        Mat dst;
        image.copyTo(dst);
        int coef=2;
        imshow( "Original_resize*2", image );
        try
        {
            for(int i = 1; i < image.rows - 1; i++) {
                for(int j = 1; j < image.cols - 1; j++) {
                    for(int k = 0; k < 3; k++) {
                        dst.at<Vec3b>(i-1, j-1)=image.at<Vec3b>(i-1, j-1)[k];
                        dst.at<Vec3b>(i-1, j)=image.at<Vec3b>(i-1, j)[k]/coef+image.at<Vec3b>(i-1, j-1)[k];
                        dst.at<Vec3b>(i-1, j+1)=image.at<Vec3b>(i-1, j)[k]/coef+image.at<Vec3b>(i-1, j-1)[k];

                    }
                }
            }
        }
    }*/
};

#endif // RESIZE_H
