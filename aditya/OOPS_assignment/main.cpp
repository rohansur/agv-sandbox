#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include "inputimg.cpp"
#include "showimg.cpp"
#include "player.cpp"
#include "boardgme.cpp"
#include "cvtbinary.cpp"
#include "if_circle.cpp"

int main()
{
  	boardgame bg;
  	player p1,p2;
    bg.play();
  	return 0;
}
    
