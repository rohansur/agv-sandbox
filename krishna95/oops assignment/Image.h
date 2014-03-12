#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <new>
#include <stdio.h>
#include <highgui.h>
#include <math.h>
#include <cv.h>
#include <cxcore.h> 

struct prop{
	char color;
	int x;
	int y;
};


#define IMGDATA(image,i,j,k) *((uchar*)&image->imageData[(i)*(image->widthStep) + (j)*(image->nChannels)+k])

class Image{
	private:
		IplImage *img;
	prop *blob;
	int **A;
	public:
	int count;
	Image CreateImage(IplImage *img);
	void color_to_binary(IplImage *bin,IplImage *img);
	void BlobDetect(IplImage *bin,int *count);
	void definearray(int count);
	void find_prop(IplImage *bin);

};