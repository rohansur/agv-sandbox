#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include "cvtbinary.cpp"
#include "inputimg.cpp"
#include "showimg.cpp"

char if_circle(cv::Mat img,int *x,int *y,char color)
{
	img=cvtbinary(img,color);
	showimg(img);
	//cvSetImageROI(img,cvRect(*x,*y,img.rows-*x,img.cols-*y));
	std::vector<cv::Vec3f> circles;
	GaussianBlur( img, img, cv::Size(9, 9), 2, 2 );
	showimg(img);
	HoughCircles(img,circles,CV_HOUGH_GRADIENT,1,img.rows/8,200,100,0,0);
	std::cout<<circles.size();
	if(circles.size()==0)
		return 0;
	else{
		*x=circles[0][0];
		*y=circles[0][1];
		return 1;
	}
}

int main()
{
	cv::Mat img;
	img=inputimg();
	showimg(img);
	if(if_circle(img,0,0,0)){
		std::cout<<"Yes detected";
	}
	showimg(img);
	return 0;
}