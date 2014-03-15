#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <new>
#include <cstdio>
#include <highgui.h>
#include <cmath>
#include <cv.h>
#include <cxcore.h> 

struct prop{
	char color;
	int x;
	int y;
};



class Image{
	private:
	cv::Mat img;
	int **A;
	public:
	prop *blob;
	int count;
	Image(cv::Mat img3);
	cv::Mat color_to_binary(cv::Mat img1);
	void BlobDetect(cv::Mat bin,int *count,cv::Mat img1);
	void definearray(int count);
	void find_prop(cv::Mat bin,cv::Mat img1);

};

#endif