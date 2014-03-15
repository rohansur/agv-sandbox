#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

cv::Mat cvtbinary(cv::Mat img,char color)
{
	int i,j;
	cv::Mat binary(img.rows,img.cols,CV_8UC1,cvScalarAll(0));
	for(i=0;i<img.rows;++i){
		for(j=0;j<img.cols;++j){
			if(img.at<cv::Vec3b>(i,j)[color]>=200)
				binary.at<uchar>(i,j)=255;
		}
	}
	return binary;
}

