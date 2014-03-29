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
        pix()
        {
            x=0;y=0;
        }
		pix(int a,int b)
        {
			x=a;
			y=b;
		}
};

class player
{
public:
  int score,x,y;
  player()
  {
    score=0;
    x=0;
    y=0;
  }
};


void MyFilledCircle( Mat img, Point center,int colour)
{
 	int thickness = -1;
	int lineType = 8;
	int w=400;
    int a,b,c;
    a=b=c=0;
    if(colour==0)
        a=255;
    else if(colour==1)
        b=255;
    else
        c=255;
	 circle( img,center, w/32.0,Scalar( a, b, c ),thickness,lineType );

}

int dice_read()
{
   int x;
   std::cout<<"Enter number on dice:";
   std::cin>>x;
   return x;
}


int main()
{
	

	int w=400;
	Mat img = Mat::zeros( w, w, CV_8UC3 );
	int a[img.rows][img.cols];
  
    int i,j,c,d,k=1;
    queue<pix> q;
    pix temp=pix(0,0);

    pix v=pix(0,0);

    pix red[10];
    pix blue[10];
    pix green[10];
    int rc, bc,gc;
    rc=bc=gc=-1;
     
    for(i=0;i<img.rows;i++)
    	for(j=0;j<img.cols;j++)
    		a[i][j]=-1;


    MyFilledCircle( img, Point( w/3.0, w/3.0),0 );
	MyFilledCircle( img, Point( w/3.0, 2*w/3.0),1 );
	MyFilledCircle( img, Point( 2*w/3.0, w/3.0),2 );
    MyFilledCircle( img, Point( 2*w/3.0, 2*w/3.0),0 );
    MyFilledCircle( img, Point( w/4.0, 2*w/3.0),1 );
    MyFilledCircle( img, Point( w/3.0, 2*w/4.0),2 );
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

                if(i!=0&&j!=0)
                {
                    if(img.at<Vec3b>(i,j)[0]>200)
                        blue[++bc]=pix(i,j);
                    else if (img.at<Vec3b>(i,j)[1]>200)
                        green[++gc]=pix(i,j);
                    else
                        red[++rc]=pix(i,j);
                }
    		}
    	}
    }
   

    player p1,p2;
    cout<<"\n\nPlayer 1 plays.\n"<<endl;
    int bc1,gc1,rc1;
    bc1=gc1=rc1=0;
    do
    {
        int x=dice_read();
        if(x%2==0)
        {
            p1.score+=2*x;
            p1.x=red[rc1].x;
            p1.y=red[rc1].y;
            rc1++;
        }
        else if(x==1)
        {
            p1.score+=10;
            p1.x=blue[bc1].x;
            p1.y=blue[bc1].y;
            bc1++;
        }
        else
        {
            p1.score+=x;
            p1.x=green[gc1].x;
            p1.y=green[gc1].y;
            gc1++;
        }

        cout<<"Current score = "<<p1.score<<endl;
    }while(rc1!=rc+1&&bc1!=bc+1&&gc1!=gc+1);
    cout<<"Player 1 stops.\n"<<endl;

    cout<<"\n\nPlayer 2 plays.\n"<<endl;
    bc1=gc1=rc1=0;
    do
    {
        int x=dice_read();
        if(x%2==0)
        {
            p2.score+=2*x;
            p2.x=red[rc1].x;
            p2.y=red[rc1].y;
            rc1++;
        }
        else if(x==1)
        {
            p2.score+=10;
            p2.x=blue[bc1].x;
            p2.y=blue[bc1].y;
            bc1++;
        }
        else
        {
            p2.score+=x;
            p2.x=green[gc1].x;
            p2.y=green[gc1].y;
            gc1++;
        }
        cout<<"Current score = "<<p2.score<<endl;
    }while(rc1!=rc+1&&bc1!=bc+1&&gc1!=gc+1);
    cout<<"Player 2 stops.\n"<<endl;

    if(p1.score>p2.score)
        cout<<"\n\nPlayer 1 wins!"<<endl;
    else if(p1.score<p2.score)
        cout<<"\n\nPlayer 2 wins!"<<endl;
    else
        cout<<"\n\nGame ends in a draw!"<<endl;
}