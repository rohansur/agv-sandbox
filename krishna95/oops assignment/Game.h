#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <new>
#include <stdio.h>
#include <highgui.h>
#include <math.h>
#include <cv.h>
#include <cxcore.h> 
#include "Player.h"
#include "Image.h"


//g++ game.cpp 'pkg-config opencv --cflags --libs'
using namespace std;

class Game{
	private:
	int dice;
	public:
	Player *winner;
	cv::Mat img;
	Player *players;
	int num_players;
	void numofplayers(int x);
	void  setplayer( Player* player,int Id,Image image);
	void setting(Image image);
};

#endif
