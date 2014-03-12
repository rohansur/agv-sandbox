#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <new>
using namespace std;
using namespace cv;
#define IMGDATA(image,i,j,k) *((uchar*)&image->imageData[(i)*(image->widthStep) + (j)*(image->nChannels)+k])

typedef struct point {
	int x;
	int y;
}point;

typedef struct prop{
	char color;
	int x;
	int y;
}prop;

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



class image{
	private:
	IplImage *img;
	prop *blob;
	int **A;
	public:
	int count;
	cvCvtColor(img,img,CV_BGR2HSV);
	void colortobinary(IplImage *bin,IplImage *img){
		IplImage *bin=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1)
		for (int i=0;i<img->height;i++ ){
			for (int j=0;j<img->width;j++){
				if (IMGDATA(img,i,j,0)==0 || IMGDATA(img,i,j,0)==180 ||IMGDATA(img,i,j,0)==240)
					IMGDATA(bin,i,j,0)=255;
				else
					IMGDATA(bim,i,j,0)=0;
			}
		}
	}
	void blobdetect(IplImage *bin,int *count){
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
	}
	void definearray(int count){
		blob=new prop[count+1];
	}
	void find_prop(IplImage *bin){
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
};




class Player {
	private:
		int score;
		int outcome;
	public:
		int id;
		point pos;
		point updatepos(point pos,int outcome){
			int min=1000;
			if (outcome%2==0){
				for (int i=0;i<count;i++)
				{
					if (blob[i].color=='r' && blob[i].x>pos.x && blob[i].y>pos.y)
					{
						if (sqrt((blob[i].x-pos.x)*(blob[i].x-pos.x)+(blob[i].y-pos.y)*(blob[i].y-pos.y))<min)
						{
							point pos2;
						pos2.x=blob[i].x;
						pos2.y=blob[i].y;
						}	
					}
				}
				if (min==1000)
					return NULL;
				else
					return pos2;
			}
			
			if (outcome==1){
				for (int i=0;i<count;i++)
				{
					if (blob[i].color=='b' && blob[i].x>pos.x && blob[i].y>pos.y)
					{
						if (sqrt((blob[i].x-pos.x)*(blob[i].x-pos.x)+(blob[i].y-pos.y)*(blob[i].y-pos.y))<min)
						{
							point pos2;
						pos2.x=blob[i].x;
						pos2.y=blob[i].y;
						}	
					}
				}
				if (min==1000)
					return NULL;
				else
					return pos2;
			}
			else
			{
				for (int i=0;i<count;i++)
				{
					if (blob[i].color=='g' && blob[i].x>pos.x && blob[i].y>pos.y)
					{
						if (sqrt((blob[i].x-pos.x)*(blob[i].x-pos.x)+(blob[i].y-pos.y)*(blob[i].y-pos.y))<min)
						{
							point pos2;
						pos2.x=blob[i].x;
						pos2.y=blob[i].y;
						}	
					}
				}
				if (min==1000)
					return NULL;
				else
					return pos2;
			}
		}
		int updatescore(int outcome,int score){
			if (outcome%2==0)
				return score+2*outcome;
			if (outcome==1)
				return score+10;
			else
				return score+outcome;
		}
		void update(point pos,int outcome,int score){
			pos=updatepos(pos,outcome);
			score=updatescore(outcome,score);
		}
		int  play(){
			outcome= rand()%6;
			update(pos,outcome,score);
		}
};

class Game{
	private:
	int dice;
	IplImage* img;
	Player *winner;
	public:
	Player *players;
	int num_players;
	void numofplayers(int x){
		players=new Player[x];
	}
	void  setplayer( Player player,int Id){
			player.id=Id;
			player.pos.x=0;
			player.pos.y=0;
		}
	void setting(Player *players){
		numofplayers(num_players);
		for (int i=0;i<num_players;i++)
			setplayer(players[i],i);
	}
	void callplayer(int id){
		if (id<num_players)
			players[id].play;
	}


};



int main(){
	Game game;
	game.img=cvLoadImage("board.jpg",1);
	cout<< "enter the number of players\n" <<endl;
	cin >> game.num_players;
	game.setting(game.players);
	while(1){
		for (int i=0;i<game.num_players;i++){
			game.callplayer(i);
			if (player[i].pos==NULL)
			{
				winner=&player[i];
				return 0;
			}
		}
	}
}
}
