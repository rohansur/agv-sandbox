#include "Image.h"
#include "Player.h"
#include "Game.h"
int main(){
	Game game;
	game.img=cvLoadImage("board.jpg",1);
	Image board=Image::CreateImage(game.img);
	cout<<"enter the number of players"<<endl;
	cin>>game.num_players;
	game.setting(game.plyers)
	while (1)
	{
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


