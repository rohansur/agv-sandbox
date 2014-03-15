#include<stdio.h>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>

void showimg(cv::Mat img)
{
	cv::imshow("window",img);
	cv::waitKey(0);
}