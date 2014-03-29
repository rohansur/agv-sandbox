#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <queue> 
using namespace std;
using namespace cv;
class pix
{
	public:
		int x;
		int y;
		pix(int a,int b){
			x=a;
			y=b;
		}
};

void MyFilledCircle( Mat img, Point center)
{
 	int thickness = -1;
	int lineType = 8;
	int w=400;
	 circle( img,
    	     center,
        	 w/32.0,
         	Scalar( 255, 0, 255 ),
         	thickness,
         	lineType );

}
int main()
{
	

	int w=400;
	Mat img = Mat::zeros( w, w, CV_8UC3 );
	//Mat img=imread("board.jpg",CV_LOAD_IMAGE_UNCHANGED);

    int a[img.rows][img.cols];
  
    int i,j,c,d,k=1;
    queue<pix> q;
    pix temp=pix(0,0);

    pix v=pix(0,0);
     
    for(i=0;i<img.rows;i++)
    	for(j=0;j<img.cols;j++)
    		a[i][j]=-1;

    for(i=0;i<img.cols/2;i++)
    	for(j=0;j<img.cols/3;j++)
    		img.at<Vec3b>(i,j)[0]=255;


    MyFilledCircle( img, Point( w/2.0, w/2.0) );
	MyFilledCircle( img, Point( w/4.0, w/4.0) );
	MyFilledCircle( img, Point( w/8.0, w/8.0) );
    MyFilledCircle( img, Point( w/3.0, w/3.0) );
	imshow("window",img);
    waitKey(0);
    destroyAllWindows();
    int dx[]={1,1,0,0,-1,-1,1,-1};
    int dy[]={0,1,1,-1,1,0,-1,-1};

    for(i=0;i<img.rows;i++)
    {
    	for(j=0;j<img.cols;j++)
    	{
    		
    		if(a[i][j]==-1)
    		{
    			a[i][j]=k;
    			temp.x=i;
    			temp.y=j;
    			q.push(temp);

    			while(!q.empty())
    			{
    				v=q.front();
    				q.pop();	
    				for(int loop=0;loop<8;loop++){
    					int newx=v.x+dx[loop];
    					int newy=v.y+dy[loop];
    					if(newx>=0 && newx<img.rows && newy>=0 && newy<img.cols && a[newx][newy]==-1){
    						
							if((img.at<Vec3b>(v.x,v.y)==img.at<Vec3b>(newx,newy))&&a[newx][newy]==-1)
							{
								a[newx][newy]=k;
								q.push(pix(newx,newy));
							}
							
    					}
    				}		
							
				}
				    			
    			cout<<"new blob at"<<i<<","<<j<<endl;
    			k++;
    		}
    	}
    }
    


    cout<<"No of blobs = "<<k-1;
    return 1;
}