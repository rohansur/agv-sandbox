#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <new>

using namespace std;

 struct point {
	int x;
	int y;
};


class Player {
private:
	int score;
	int outcome;
	char reqcolor;
	public:
	int id;
	point pos;
	void Reqcolor(int outcome);
	point updatepos(point pos,int outcome);
	int updatescore(int outcome,int score);
	void update(point pos,int outcome,int score);
	int  play();
};
