#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <vector>
#include <assert.h>
#include <cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
using namespace cv;
using namespace std;

typedef vector<double> Array;
typedef vector<Array> Matrix;
typedef vector<Matrix> Image;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cout << "Loading image..." << endl;
    int window[9];
    Mat image = cv::imread("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg", 1);
    imshow( "Original Image", image);
    // Split the image into different channels
    vector<Mat> rgbChannels(3);
    split(image, rgbChannels);

    // Show individual channels
    Mat zero, r_img, g_img, b_img;
    zero = Mat::zeros(Size(image.cols, image.rows), CV_8UC1);

    // Showing Red Channel
    // G and B channels are kept as zero matrix for visual perception

    vector<Mat> channels;
    channels.push_back(zero);
    channels.push_back(zero);
    channels.push_back(rgbChannels[2]);

    /// Merge the three channels
    merge(channels, r_img);
    imshow("Red", r_img);

    for(int row = 1; row <= image.rows; ++row)
        {
            for(int col = 1; col <= image.cols; ++col)
            {
                //neighbor pixel values are stored in window including this pixel
                window[0] = r_img.at<cv::Vec3f>(row-1,col-1)[2];
                window[1] = r_img.at<cv::Vec3f>(row-1,col)[2];
                window[2] = r_img.at<cv::Vec3f>(row-1,col+1)[2];
                window[3] = r_img.at<cv::Vec3f>(row,col-1)[2];
                window[4] = r_img.at<cv::Vec3f>(row,col)[2];
                window[5] = r_img.at<cv::Vec3f>(row,col+1)[2];
                window[6] = r_img.at<cv::Vec3f>(row+1,col-1)[2];
                window[7] = r_img.at<cv::Vec3f>(row+1,col)[2];
                window[8] = r_img.at<cv::Vec3f>(row+1,col+1)[2];

                //sort window array
                insertionSort(window,9);

                image.at<cv::Vec3f>(row,col)[2] =window[4];
            }
        }


        // Showing Green Channel
        vector<Mat> channels1;
        channels1.push_back(zero);
        channels1.push_back(rgbChannels[1]);
        channels1.push_back(zero);
        merge(channels1, g_img);
        imshow("Green", g_img);
        for(int row = 1; row <= image.rows; ++row)
            {
                for(int col = 1; col <= image.cols; ++col)
                {
                    //neighbor pixel values are stored in window including this pixel
                    window[0] = r_img.at<cv::Vec3f>(row-1,col-1)[1];
                    window[1] = r_img.at<cv::Vec3f>(row-1,col)[1];
                    window[2] = r_img.at<cv::Vec3f>(row-1,col+1)[1];
                    window[3] = r_img.at<cv::Vec3f>(row,col-1)[1];
                    window[4] = r_img.at<cv::Vec3f>(row,col)[1];
                    window[5] = r_img.at<cv::Vec3f>(row,col+1)[1];
                    window[6] = r_img.at<cv::Vec3f>(row+1,col-1)[1];
                    window[7] = r_img.at<cv::Vec3f>(row+1,col)[1];
                    window[8] = r_img.at<cv::Vec3f>(row+1,col+1)[1];

                    //sort window array
                    insertionSort(window,9);

                    image.at<cv::Vec3f>(row,col)[1] =window[4];
                }
            }

        // Showing Blue Channel
        vector<Mat> channels2;
        channels2.push_back(rgbChannels[0]);
        channels2.push_back(zero);
        channels2.push_back(zero);
        merge(channels2, b_img);
        imshow("Blue", b_img);
        for(int row = 1; row <= image.rows; ++row)
            {
                for(int col = 1; col <= image.cols; ++col)
                {
                    //neighbor pixel values are stored in window including this pixel
                    window[0] = r_img.at<cv::Vec3f>(row-1,col-1)[0];
                    window[1] = r_img.at<cv::Vec3f>(row-1,col)[0];
                    window[2] = r_img.at<cv::Vec3f>(row-1,col+1)[0];
                    window[3] = r_img.at<cv::Vec3f>(row,col-1)[0];
                    window[4] = r_img.at<cv::Vec3f>(row,col)[0];
                    window[5] = r_img.at<cv::Vec3f>(row,col+1)[0];
                    window[6] = r_img.at<cv::Vec3f>(row+1,col-1)[0];
                    window[7] = r_img.at<cv::Vec3f>(row+1,col)[0];
                    window[8] = r_img.at<cv::Vec3f>(row+1,col+1)[0];

                    //sort window array
                    insertionSort(window,9);

                    image.at<cv::Vec3f>(row,col)[0] =window[4];
                }
            }
        imshow("Median filter", image);
    cout << "Done!" << endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}

