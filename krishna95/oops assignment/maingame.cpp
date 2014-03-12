#include "Image.h"
#include "Player.h"
#include "Game.h"
int main(){
	Game game;
	game.img=cvLoadImage("board.odg",1);
	
	Image board(game.img);
	cout<<"enter the number of players"<<endl;
	cin>>game.num_players;
	game.setting(game.players);
	while (1)
	{
		for (int i=0;i<game.num_players;i++){
			game.players[i].play();
			if (game.players[i].pos.x==0 && game.players[i].pos.y==0)
			{
				game.winner=&game.players[i];
				return 0;
			}
		}
	}
}
}


