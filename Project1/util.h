
#pragma once
#include <random>

//mporw na prosthesw edw random synarthsh
float rand0to1();
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };



struct Disk {
	float cx, cy;
	float radius;

};