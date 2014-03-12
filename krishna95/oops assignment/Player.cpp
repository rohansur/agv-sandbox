#include "Player.h"




void Player::Reqcolor(int outcome){
	if (outcome%2==0)
		reqcolor='r';
	else
		if (outcome==1)
		reqcolor='b';
		else
			reqcolor='g';void Image::definearray(int count){
		blob=new prop[count+1];
	}

	}


point Player::RequiredPos(point pos,int outcome){
int min=1000;
point pos2;
pos2.x=pos2.y=0;
Player::Reqcolor(outcome);
for (int i=0;i<count;i++)
{
	if (blob[i].color==reqcolor && blob[i].x>pos.x && blob[i].y>pos.y)
	{
		if (sqrt((blob[i].x-pos.x)*(blob[i].x-pos.x)+(blob[i].y-pos.y)*(blob[i].y-pos.y))<min)
		{
			pos2.x=blob[i].x;
			pos2.y=blob[i].y;
		}	
	}
}
	return pos2;
}
			



point Player::updatepos(point pos,int outcome){
	pos=RequiredPos(pos,outcome);
}

int Player::updatescore(int outcome,int score){
	if (outcome%2==0)
		return score+2*outcome;
	if (outcome==1)
		return score+10;
	else
		return score+outcome;
}

void Player::update(point pos,int outcome,int score){
	pos=updatepos(pos,outcome);
	score=updatescore(outcome,score);
}

int Player::play(){
	outcome= rand()%6;
	update(pos,outcome,score);
}




