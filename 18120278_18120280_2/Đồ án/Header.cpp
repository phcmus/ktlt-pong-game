#include "Header.h"
#include <iostream>
#include <conio.h>
using namespace std;
bool VaCham(CircleShape& Cir, RectangleShape& Rect) //Ham kiem tra va cham giua hinh tron va hinh chu nhat
{
	FloatRect circle = Cir.getGlobalBounds();//Tao bien luu thong tin hinh tron
	FloatRect rectangle = Rect.getGlobalBounds();//Tao bien luu thong tin hinh chu nhat
	return circle.intersects(rectangle);//Tra ve ket qua xem hinh tron co va cham hinh chu nhat
}
bool VaChamEnd(CircleShape& Cir, CircleShape& Rect) //Ham kiem tra va cham giua hinh tron va hinh chu nhat
{
	FloatRect circle = Cir.getGlobalBounds();//Tao bien luu thong tin hinh tron
	FloatRect rectangle = Rect.getGlobalBounds();//Tao bien luu thong tin hinh chu nhat
	return circle.intersects(rectangle);//Tra ve ket qua xem hinh tron co va cham hinh chu nhat
}

bool LimitPlayer(RectangleShape& Rect1, RectangleShape& Rect2)//Ham kiem tra va cham giua hinh chu nhat 1 va hinh chu nhat 2
{
	FloatRect Rectangle1 = Rect1.getGlobalBounds();//Tao bien luu thong tin hinh chu nhat 1
	FloatRect Rectangle2 = Rect2.getGlobalBounds();//Tao bien luu thong tin hinh chu nhat 2
	return Rectangle1.intersects(Rectangle2);//Tra ve ket qua xem hinh chu nhat 1 co va cham hinh chu nhat 2
}

void InKetQua(PlayerScore player1, PlayerScore player2)
{
	int winner = (player1.score > player2.score) ? 1 : 2;
	cout << "Winner: " << winner << endl;
	cout << "Tong so diem: " << endl;
	cout << "\tPlayer 1: " << player1.score << endl << "\tPlayer 2: " << player2.score << endl;
	_getch();
}
