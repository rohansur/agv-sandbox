#include "Game.h"

void Game::numofplayers(int x){
		cout<<"starting to create an array of players"<<endl;
		players=new Player[x];
		cout<<"array of players created"<<endl;
	}
	void  Game::setplayer(Player* player,int Id,Image image){
			cout<<"initialising the values for player"<<endl;
			player->id=Id;
			player->pos.x=0;
			player->pos.y=0;
			player->score=0;
			player->_count=image.count;
			
		}
	void Game::setting(Image image){
		cout<<"enter the setting zone"<<endl;
		numofplayers(num_players);
		for (int i=0;i<num_players;i++)
			setplayer(&players[i],i,image);
		cout<<"initialising done"<<endl;
	}
<<<<<<< HEAD
	
=======
>>>>>>> 06d2ba277a670859eec28c9fc13fb8ed2bd719a5
