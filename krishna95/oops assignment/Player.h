#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <new>
#include "Image.h"

using namespace std;

 struct point {
	int x;
	int y;
};


class Player {
private:
	int outcome;
	char reqcolor;
	public:
	int score;
	int id,_count;
	point pos;

	void Reqcolor(int outcome);
	point RequiredPos(point pos,int outcome,prop *blob);
	point updatepos(point pos,int outcome,prop *blob);
	int updatescore(int outcome,int score);
	void update(int outcome,prop *blob);
	void  play(prop *blob);
};

<<<<<<< HEAD
#endif 
=======
#endif 
>>>>>>> 06d2ba277a670859eec28c9fc13fb8ed2bd719a5
