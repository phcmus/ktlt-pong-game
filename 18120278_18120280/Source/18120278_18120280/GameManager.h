#pragma once
#include "Ball.h"
#include "Paddle.h"
#include <Windows.h>
#include <ctime>
#include <conio.h>

class GameManager
{
private:
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	Ball* ball;
	Paddle* player1;
	Paddle* player2;
public:
	GameManager(int w, int h);
	~GameManager();
	void ScoreUp(Paddle* player);
	void DrawBorder();
	void Draw();
	void Input();
	void Logic();
	void Run();
};

