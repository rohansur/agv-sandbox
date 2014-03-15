#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Image.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
using namespace std;
int main(){
	Game game;
	game.img=cv::imread("board.jpg",1);
	
	cv::namedWindow("win",0);
	cv::imshow("win",game.img);
	cv::waitKey(0);
	Image board(game.img);
	cout<<"enter the number of players"<<endl;
		
		cin>>game.num_players;
		cout<<"done"<<endl;
		game.setting(board);
		cout<<game.players[0].pos.x<<" "<<game.players[0].pos.y<<" "<< game.players[0].score<<endl;

	cout<<"entering the infinite loop"<<endl;
	while (1)
	{
		
		for (int i=0;i<game.num_players;i++){
			cout<<"playing"<<" "<<i<<endl;
			cout<<game.players[i].pos.x<<" "<<game.players[i].pos.y<<endl;
			game.players[i].play(board.blob);
			cout<<game.players[i].pos.x<<" "<<game.players[i].pos.y<<endl;
			//cv::waitKey(0);
			if (game.players[i].pos.x==0 && game.players[i].pos.y==0)
			{
				game.winner=&game.players[i];
				cout<<"winner is player "<<i<<endl;
				return 0;
			}
		}
	}
}


