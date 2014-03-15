#include <iostream>
#include "player.cpp"
#include "if_circle.cpp"

class boardgame
{
public:
  cv::Mat board;
  int dice_read()
  {
    int x;
    do{
      std::cout<<"Enter number on dice:";
      std::cin>>x;
    }
    while(x<0 || x>6);
    return x;
  }
  char score(int x,int *score,int *pose_x,int *pose_y)
  {
    if(!x&1){
      (*score)*=2;
      if(if_circle(board,*pose_x,*pose_y,2)
        return 1;
    }
    else if(x==1){
      (*score)+=10;
      if(if_circle(board,*pose_x,*pose_y,0))
        return 1;
    }
    else{
      (*score)+=x;
      if(if_circle(board,*pose_x,*pose_y,1))
        return 1;
    }
    return 0;
  }
  void play()
  {
    while(1){
      std::cout<<"Player 1 plays\n";
      if(score(bg.dice_read(),&p1.score,&p1.x,&p1.y))
          std::cout<<"Game continues\n";
      else{
          std::cout<<"Player 1 wins\n";
          return;
      }
      std::cout<<"Player 2 Plays\n";
      if(score(bg.dice_read(),&p2.score,&p2.x,&p2.y))
          std::cout<<"Game continues\n";
      else{
          std::cout<<"Player 1 wins\n";
          return;
      }
    }
  }
};

