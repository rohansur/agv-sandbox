#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <new>
#include <stdio.h>
#include <highgui.h>
#include <math.h>
#include <cv.h>
#include <cxcore.h> 


//g++ game.cpp 'pkg-config opencv --cflags --libs'
using namespace std;

class Game{
	private:
	int dice;
	public:
	Player *winner;
	IplImage *img;
	Player *players;
	int num_players;
	void numofplayers(int x);
	void  setplayer( Player player,int Id);
	void setting(Player* players);
};
