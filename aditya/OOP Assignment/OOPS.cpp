#include<iostream>

unsigned long find_blue(int *ptr)
{
  return 1;
}

class boardgame
{
public:
  int dice_read()
  {
    int x;
    std::cout<<"Enter number on dice:";
    std::cin>>x;
    return x;
  }
  char score(int x,int *score,int *ptr)
  {
    if(!x&1){
      (*score)*=2;
      find_blue(ptr);
      if(ptr==0)
	return 0;
    }
    else if(x==1){
      (*score)+=10;
      find_blue(ptr);
      if(ptr==0)
	return 0;
    }
    else{
      (*score)+=x;
      find_blue(ptr);
      if(ptr==0)
	return 0;
    }
    return 1;
  }
};

class player
{
private:
  int score,*ptr;
public:
  player()
  {
    score=0;
  }
};

int main()
{
  boardgame bg;
  player p1,p2;
  while(1){
    std::cout<<"Player 1 plays\n";
    if(bg.score(bg.dice_read(),&p1.score,p1.ptr))
      std::cout<<"Game continues\n";
    else
      break;
    std::cout<<"Player 2 Plays\n";
    if(bg.score(bg.dice_read(),&p2.score,p2.ptr))
      std::cout<<"Game continues\n";
    else
      break;
  }
  return 0;
}
    
