#ifndef GAUSSIANNOISE_H
#define GAUSSIANNOISE_H
#include<iostream>
#include <random>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

class GaussianNoise
{
public:
    string image_path;
    Mat image;
public:
    GaussianNoise(string path)
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
    bool AddGaussianNoise(const Mat mSrc, Mat &mDst,double Mean=0.0, double StdDev=10.0)
    {
        if(mSrc.empty())
        {
            cout<<"[Error]! Input Image Empty!";
            return 0;
        }

        Mat mGaussian_noise = Mat(mSrc.size(),CV_16SC3);
        randn(mGaussian_noise,Scalar::all(Mean),Scalar::all(StdDev));

//        for (int Rows = 0; Rows < mSrc.rows; Rows++)
//        {
//            for (int Cols = 0; Cols < mSrc.cols; Cols++)
//            {
//                Vec3b Source_Pixel= mSrc.at<Vec3b>(Rows,Cols);
//                Vec3b &Des_Pixel= mDst.at<Vec3b>(Rows,Cols);
//                Vec3s Noise_Pixel= mGaussian_noise.at<Vec3s>(Rows,Cols);

//                for (int i = 0; i < 3; i++)
//                {
//                    int Dest_Pixel= Source_Pixel.val[i] + Noise_Pixel.val[i];
//                    Des_Pixel.val[i]= Clamp(Dest_Pixel);
//                }
//            }
//        }

//        return true;
    }
    void applyNoise(double mean=0.0, double stdDev=10.0)
    {
        Mat dst;
        image.copyTo(dst);
        int noise_check;
        int salt_or_pepper = 1;
        // 1 => salt
        // 2 => pepper
        std::default_random_engine generator;
        Mat mGaussian_noise = Mat(10, 10,CV_16SC3);
        randn(mGaussian_noise,Scalar::all(mean),Scalar::all(stdDev));
        cout<<mGaussian_noise;
//        std::uniform_int_distribution<int> distribution(0,percentage);
//        imshow( "Original_image", image );
//          try
//          {
//              for(int i = 0; i < image.rows; i++) {
//                  for(int j = 0; j < image.cols; j++) {
//                      noise_check = distribution(generator);
//                      if(noise_check == percentage) {
//                          if(salt_or_pepper == 1) {
//                              dst.at<Vec3b>(i, j)[0] = 255;
//                              dst.at<Vec3b>(i, j)[1] = 255;
//                              dst.at<Vec3b>(i, j)[2] = 255;
//                              salt_or_pepper = 0;
//                          } else {
//                              dst.at<Vec3b>(i, j)[0] = 0;
//                              dst.at<Vec3b>(i, j)[1] = 0;
//                              dst.at<Vec3b>(i, j)[2] = 0;
//                              salt_or_pepper = 1;
//                          }
//                      }
//                  }
//              }
//              imshow( "Image_with_noise_salt_and_pepper", dst );
//          }
//          catch (Exception e)
//          {
//          cout<<e.msg;
//          }
    }
};

#endif // GAUSSIANNOISE_H
