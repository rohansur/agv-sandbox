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
	Image(IplImage *img);
	IplImage* color_to_binary(IplImage *img);
	void BlobDetect(IplImage *bin,int *count);
	void definearray(int count);
	void find_prop(IplImage *bin);

};
