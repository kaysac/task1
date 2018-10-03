#include "widget.h"
#include <QApplication>
#include <highgui.h>  //包含opencv库头文件
#include <cv.h>
#include <opencv2/opencv.hpp>
#include<iostream>
#include<stdio.h>
using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
   Mat frame;
   VideoCapture cap;
   cap.open(0);
   int deviceID=0;
   int apiID=cv::CAP_ANY;
   cap.open(deviceID + apiID);
   if (!cap.isOpened())
   {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
   }
   cout << "Start grabbing" << endl
       << "Press any key to terminate" << endl;
   char key;
   while (1)
   {
        key=waitKey(5) ;
        cap.read(frame);
        if (frame.empty())
        {
                   cerr << "ERROR! blank frame grabbed\n";
                   break;
        }
        imshow("Live", frame);
        if (key == 83)
        {
            imwrite("IMAGE.jpg",frame);//图片保存到本工程目录中
            imshow("PICTURE",frame);
        }
        if (key == 27)
        break;
   }
   return 0;


}
