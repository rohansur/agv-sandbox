#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <new>
//g++ game.cpp 'pkg-config opencv --cflags --libs'
using namespace std;

class Game{
	private:
	int dice;
	IplImage *img;
	Player *winner;
	public:
	Player *players;
	int num_players;
	void numofplayers(int x);
	void  setplayer( Player player,int Id);
	void setting(Player *players);
	void callplayer(int id);
}