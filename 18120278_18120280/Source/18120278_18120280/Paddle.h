#pragma once
#include <iostream>
using namespace std;
class Paddle
{
private:
	int x, y;
	int originalX, originalY;
public:
	Paddle();
	Paddle(int posX, int posY);
	void Reset();
	int getX();
	int getY();
	void moveUp();
	void moveDown();
	friend ostream& operator<<(ostream& o, Paddle c);
};
