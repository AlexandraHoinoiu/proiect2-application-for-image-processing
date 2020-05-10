#ifndef SALTPEPPERNOISE_H
#define SALTPEPPERNOISE_H
#include<iostream>
#include <stdlib.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

class SaltPepperNoise
{
    string image_path;
    Mat image;
public:
    SaltPepperNoise(string path)
    {
        this->image_path = path;
        this->setImage();
    }

    void setImage()
    {
        // Load an image
        this->image = imread(image_path, IMREAD_COLOR);
        bool k = !image.data;
        if( !image.data )
        { exit(1); }
    }
    void applyNoise(int percentage)
    {
        Mat dst;
        image.copyTo(dst);
        int noise_check;
        int salt_or_pepper = 1;
        // 1 => salt
        // 2 => pepper
        imshow( "Original_image1", image );
          try
          {
              for(int i = 0; i < image.rows; i++) {
                  for(int j = 0; j < image.cols; j++) {
                      noise_check = rand() % 100 + 1;
                      if(noise_check <= percentage) {
                          if(salt_or_pepper == 1) {
                              dst.at<Vec3b>(i, j)[0] = 255;
                              dst.at<Vec3b>(i, j)[1] = 255;
                              dst.at<Vec3b>(i, j)[2] = 255;
                              salt_or_pepper = 0;
                          } else {
                              dst.at<Vec3b>(i, j)[0] = 0;
                              dst.at<Vec3b>(i, j)[1] = 0;
                              dst.at<Vec3b>(i, j)[2] = 0;
                              salt_or_pepper = 1;
                          }
                      }
                  }
              }
              imwrite( "C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\Image_with_noise_salt_and_pepper.jpg", dst );
              imshow( "Image_with_noise_salt_and_pepper", dst );
          }
          catch (Exception e)
          {
          cout<<e.msg;
          }
    }

};

#endif // SALTPEPPERNOISE_H
