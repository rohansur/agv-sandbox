#include "Image.h"

struct point {
	int x;
	int y;
}point;


struct ind
{
	int x;int y;
	struct ind* next;
};
struct ind *front,*rear;

void enqueue(int x,int y){
	struct ind* n;
	n=(struct ind*)malloc(sizeof(struct ind));
	n->x=x;
	n->y=y;
	n->next=NULL;
	if(front==NULL){front=n;rear=front;}
	else {rear->next=n;rear=n;}
}


void dequeue(){
	struct ind* t;
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

void Image::color_to_binary(IplImage *bin,IplImage *img)
{
	IplImage *bin=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
		for (int i=0;i<img->height;i++ ){
			for (int j=0;j<img->width;j++){
				if (IMGDATA(img,i,j,0)==0 || IMGDATA(img,i,j,0)==180 ||IMGDATA(img,i,j,0)==240)
					IMGDATA(bin,i,j,0)=255;
				else
					IMGDATA(bin,i,j,0)=0;
			}
		}
}

Image Image::CreateImage(IplImage *img){
	img=img;
	Image::color_to_binary(bin,img);
	BlobDetect(bin,&count);
}



void Image::BlobDetect(IplImage *bin,int *count)
{
	int i,j,x,y,wd=bin->width,ht=bin->height;
	 	A=new int*[height];
	 	for(i=0;i<ht;i++)
			 A[i]=new int[width];
	 	for(i=0;i<ht;i++){
			 for(j=0;j<wd;j++){
			
			 	A[i][j]=-1;
			 }
		}
	 for(i=0;i<ht;i++){
		 for(j=0;j<wd;j++){
			 if(IMGDATA(bin,i,j,0)==255){
				 if(A[i][j]==-1){
					 *count=*count+1;
				 	enqueue(i,j);
					while(qempty()==0){
				 		qfront(&x,&y);
				 		int k,l;
				 		dequeue();
				 		for(k=x-1;k<=x+1;k++){
							 for(l=y-1;l<=y+1;l++){
								 if((k<ht)&&(l<wd)&&(k>=0)&&(l>=0)&&(A[k][l]==-1) && IMGDATA(bin,k,l,0)==255){
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
	Image::definearray(count);	
	Image::find_prop(bin);
}



void Image::definearray(int count){
		blob=new prop[count+1];
	}


void Image::find_prop(IplImage *bin){
		int c_x,c_y,c_pixel;
		for (int k=1;k<=count;k++)
		{
			for (int i=0;i<bin->height;i++)
			{
				for (j=0;j<img->width;j++){
					if (A[i][j]==k)
					{
						c_x+=j;
						c_y+=i;
						c_pixel++;
					}
				}
			}
		}
		blob[k].x=c_x/c_pixel;
		blob[k].y=c_y/c_pixel;
		c_x=c_y=c_pixel=0;
		if (IMGDATA(img,i,j,0)==0)
			blob[k].color='r';
		if (IMGDATA(img,i,j,0)==180)
			blob[k].color='b';
		if (IMGDATA(img,i,j,0)==240)
			blob[k].color='g';
	}
}





