#pragma once
#include <SFML/Graphics.hpp> 
#include "PlayerScore.h"
using namespace sf;

bool VaCham(CircleShape& Cir, RectangleShape& Rect);
bool VaChamEnd(CircleShape& Cir, CircleShape& Rect);
bool LimitPlayer(RectangleShape& Rect1, RectangleShape& Rect2);
void InKetQua(PlayerScore player1, PlayerScore player2);