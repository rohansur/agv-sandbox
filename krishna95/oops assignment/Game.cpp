#include "Game.h"

void Game::numofplayers(int x){
		players=new Player[x];
}
void Game::setplayer( Player player,int Id){
	player.id=Id;
	player.pos.x=0;
	player.pos.y=0;
}
void Game::setting(Player *players){
	numofplayers(num_players);
	for (int i=0;i<num_players;i++)
		setplayer(players[i],i);
}
	
