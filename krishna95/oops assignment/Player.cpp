#include "Player.h"




void Player::Reqcolor(int outcome){
	if (outcome%2==0)
		reqcolor='r';
	else
		if (outcome==1)
		reqcolor='b';
		else
			reqcolor='g';
		cout<<"required colour is "<<reqcolor<<endl;
	}


point Player::RequiredPos(point pos,int outcome,prop *blob){
int min=1000;
point pos2;
pos2.x=pos2.y=0;
Player::Reqcolor(outcome);
for (int i=0;i<_count;i++)
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
	cout<<"pos 2 is "<<pos2.x<<" "<<pos2.y<<endl;
	return pos2;
}
			



point Player::updatepos(point pos,int outcome,prop *blob){
	pos=RequiredPos(pos,outcome,blob);
	return pos;
}

int Player::updatescore(int outcome,int score){
	if (outcome%2==0)
		return score+2*outcome;
	if (outcome==1)
		return score+10;
	else
		return score+outcome;
}

void Player::update(int outcome,prop *blob){
	cout<<"updating "<<endl;
	pos=updatepos(pos,outcome,blob);
	cout<<"initial score is "<<score<<endl;
	score=updatescore(outcome,score);
	cout<<"score is "<<score<<endl;
}

void Player::play(prop *blob){
	outcome= rand()%6;
	cout<<"outcome is "<<outcome<<endl;
	update(outcome,blob);
}










