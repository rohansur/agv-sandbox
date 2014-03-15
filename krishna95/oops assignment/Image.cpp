#include "Image.h"
#include <cstdlib>
using namespace std;
struct point {
	int x;
	int y;
}point;


struct ind
{
	int x;int y;
	struct ind* next;
};
 ind *front,*rear;

void enqueue(int x,int y){
	 ind* n;
	n=(ind*)malloc(sizeof(ind));
	n->x=x;
	n->y=y;
	n->next=NULL;
	if(front==NULL){front=n;rear=front;}
	else {rear->next=n;rear=n;}
}


void dequeue(){
	ind* t;
	t=front;
	front=t->next;
	free(t);
}


void qfront(int* x,int *y){
	if(front!=NULL){
	*x=front->x;
	*y=front->y;}
	return;
}


int qempty(){
	if(front==NULL)return 1;
	return 0;}

cv::Mat Image::color_to_binary(cv::Mat img1)
{
	cv::Mat bin(img1.rows,img1.cols,CV_8UC1,cvScalarAll(0));
		for (int i=0;i<img1.rows;i++ ){
			for (int j=0;j<img1.cols;j++){
				if (img1.at<cv::Vec3b>(i,j)[0]==0 && img1.at<cv::Vec3b>(i,j)[1]==0 && img1.at<cv::Vec3b>(i,j)[2]==0 )
					bin.at<uchar>(i,j)=0;
				else
					bin.at<uchar>(i,j)=255;
			}
		}
		return bin;
}

void Image::find_prop(cv::Mat bin,cv::Mat img1){
		cout<<"find_prop has started"<<endl;
		int c_x,c_y,c_pixel,i,j,k;
		for (k=1;k<=count;k++)
		{
			for ( i=0;i<bin.rows;i++)
			{
				for ( j=0;j<bin.cols;j++){
					if (A[i][j]==k)
					{
						c_x+=j;
						c_y+=i;
						c_pixel++;
					}
				}
			}
		
		blob[k].x=c_x/c_pixel;
		blob[k].y=c_y/c_pixel;
		c_x=c_y=c_pixel=0;
		if (img1.at<cv::Vec3b>(blob[k].y,blob[k].x)[0]==255)
			{ cout<<"here"<<endl;blob[k].color='b';}
		if (img1.at<cv::Vec3b>(blob[k].y,blob[k].x)[1]==255)
			{ cout<<"here"<<endl;blob[k].color='g';}
		if (img1.at<cv::Vec3b>(blob[k].y,blob[k].x)[2]==255)
			{ cout<<"here"<<endl;blob[k].color='r';}
	}
}


void Image::definearray(int count){
		cout<<"define array has started"<<endl;
		blob=new prop[count+1];
		cout<<"define array has ended"<<endl;
	}

void Image::BlobDetect(cv::Mat bin,int *count,cv::Mat img1)
{
	int i,j,x,y,wd=bin.cols,ht=bin.rows;
	cout<<"rowss is "<<ht<<endl;
	cout <<"cols is "<<wd<<endl;
	 	A=new int*[ht];
	 	for(i=0;i<ht;i++)
			 A[i]=new int[wd];
	 	for(i=0;i<ht;i++){
			 for(j=0;j<wd;j++){
			 	A[i][j]=-1;
			 }
		}
		cout<<"A matrix is created"<<endl;
	 for(i=0;i<ht;i++){
		 for(j=0;j<wd;j++){
			 if(bin.at<uchar>(i,j)==255){
				 if(A[i][j]==-1){
					 *count=*count+1;
				 	enqueue(i,j);
					while(qempty()==0){
				 		qfront(&x,&y);
				 		int k,l;
				 		dequeue();
				 		for(k=x-1;k<=x+1;k++){
							 for(l=y-1;l<=y+1;l++){
								 if(k<ht && l<wd && k>=0 && l>=0 && A[k][l]==-1 && bin.at<uchar>(k,l)==255){
									 enqueue(k,l);
							 		A[k][l]=*count;
							 	}
					 		}
						}
						A[x][y]=*count;
					}
				 }
			 }
		 }
	}
	std::cout<<"number of blobs"<<*count<<endl;

	Image::definearray(*count);	
	Image::find_prop(bin,img1);
}

 Image::Image(cv::Mat img3){
	img=img3;
	count=0;
	cv::Mat bin(img.rows,img.cols,CV_8UC1,cvScalarAll(0));
	 bin=Image::color_to_binary(img);
	cv::namedWindow("won",0);
	cv::imshow("won",bin);
	cv::waitKey(0);
	BlobDetect(bin,&count,img);
}









