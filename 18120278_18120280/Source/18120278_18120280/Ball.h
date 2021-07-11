#pragma once
#include <iostream>
using namespace std;
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };
class Ball
{
private:
	int x, y;
	int originalX, originalY;
	eDir direction;
public:
	Ball(int posX, int posY);
	void Reset();
	void changeDirection(eDir d);
	void randomDirection();
	int getX();
	int getY();
	eDir getDirection();
	void Move();
	friend ostream& operator<<(ostream& o, Ball c);
};