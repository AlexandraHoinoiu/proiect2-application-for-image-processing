#ifndef DECREASE_H
#define DECREASE_H
#include <iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

class Decrease
{
private:
    string image_path;
    Mat image;
    int coef;
public:
    Decrease(string path,int coef)
    {
        this->image_path = path;
        this->coef=coef;
        this->setImage();
    }
    void setImage()
    {
        // Load an image
        this->image = imread(image_path, IMREAD_COLOR);

        if( !image.data )
        { exit(1); }
    }
    void decrease(){
        Mat M(image.rows/coef,image.cols/coef, CV_8UC3, Scalar(0,0,0));
        int x,y;
        imshow( "Image_before_decrease", image );
            for(int i = 0; i < image.rows/coef; i++) {
                for(int j = 0; j < image.cols/coef; j++) {
                    for(int k = 0; k < 3; k++) {
                        x=floor(i*coef);
                        y=floor(j*coef);
                        if(x==0) x=1;
                        if(y==0) y=1;
                        M.at<Vec3b>(i,j)[k]=image.at<Vec3b>(x,y)[k];
                    }
                }
            }

    imshow( "Image_after_decrease", M );

}

};
#endif // DECREASE_H
