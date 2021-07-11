#include "Header.h"
#include <SFML/Graphics.hpp>
#include "PlayerScore.h"
#include <iostream>
using namespace sf;
using namespace std;

PlayerScore player1Score, player2Score;

int main()
{
	Font FONT;//Tao bien font chu
	FONT.loadFromFile("ARCADECLASSIC.TTF");//Tai font tu file 

	Text Player1Win;//Tao bien the hien nguoi choi 1 thang
	Player1Win.setFont(FONT);//Dat font cho bien
	Player1Win.setString("You win");//Truyen vao diem nguoi choi 1 
	Player1Win.setFillColor(Color::Black);//Chinh mau la den
	Player1Win.setCharacterSize(48);//Chinh kich thuoc la 48
	Player1Win.setPosition(20, 20);//Dat diem o vi tri (20;20) ben san nguoi choi 1

	Text Player2Win;//Tao bien the hien nguoi choi 2 thang
	Player2Win.setFont(FONT);//Dat font cho bien
	Player2Win.setString("You win");//Truyen vao noi dung cho biet nguoi choi 2 thang
	Player2Win.setFillColor(Color::Black);//Chinh mau la den
	Player2Win.setCharacterSize(48);//Chinh kich thuoc la 48
	Player2Win.setPosition(220, 20);//Dat o vi tri (220;20) ben san nguoi choi 2

	VideoMode Videomode(820, 410);//Tao cua so game voi kich thuoc 410x410

	RenderWindow Window(Videomode, "PONG");//Dat ten cho cua so game

	CircleShape BALL;//Tao doi tuong qua bong voi hinh tron
	BALL.setFillColor(Color::Red);//Dat mau cho qua bong la do
	BALL.setRadius(10);//Tao ban kinh qua bong la 10
	BALL.setPosition(405, 200);//Dat vi tri qua bong ban dau la 200x200

	RectangleShape FirstPlayer;//Tao doi tuong thanh hung bong nguoi choi 1 la hinh chu nhat
	FirstPlayer.setFillColor(Color::Black);//Dat cho no mau den
	FirstPlayer.setSize(sf::Vector2f(10, 100));//Dat no voi kich thuoc la 10x100
	FirstPlayer.setPosition(10, 200);//Dat o vi tri (10;200)

	RectangleShape SecondPlayer;//Tao doi tuong thanh hung bong nguoi choi 2 la hinh chu nhat
	SecondPlayer.setFillColor(Color::Black);//Dat cho no mau den
	SecondPlayer.setSize(Vector2f(10, 100));//Dat no voi kich thuoc la 10x100
	SecondPlayer.setPosition(800, 200);//Dat o vi tri (390x200)

	RectangleShape BienTrai;//Tao gioi han trai cho nguoi choi 1, bong cham vao day la nguoi choi 1 thua
	BienTrai.setFillColor(Color::Blue);//Dat mau la xanh duong
	BienTrai.setSize(Vector2f(10, 410));//Dat kich thuoc la 10x410
	BienTrai.setPosition(0, 0);//Dat o vi tri (0;0)

	RectangleShape BienPhai;//Tao gioi han trai cho nguoi choi 2, bong cham vao day la nguoi choi 2 thua
	BienPhai.setFillColor(Color::Blue);//Dat mau la xanh duong
	BienPhai.setSize(Vector2f(10, 410));//Dat kich thuoc la 10x410
	BienPhai.setPosition(810, 0);//Dat o vi tri (400;0)

	RectangleShape CanhTren;//Khai thanh chan tren cua cua so game
	CanhTren.setFillColor(Color::Blue);//Dat mau la xanh duong
	CanhTren.setSize(Vector2f(10, 810));//Kich thuoc la 10x400
	CanhTren.setPosition(810, 0);//Dat o vi tri (400;0) 
	CanhTren.rotate(90);//Xoay thanh chan 90 do

	RectangleShape CanhDuoi;//Khai bao thanh chan duoi cua cua so game
	CanhDuoi.setFillColor(Color::Blue);//Dat mau la xanh duong
	CanhDuoi.setSize(Vector2f(10, 810));//Kich thuoc la 10x400
	CanhDuoi.setPosition(810, 400);//Dat o vi tri (400;400) 
	CanhDuoi.rotate(90);//Xoay thanh chan 90 do

#pragma region Vat can
	RectangleShape x2;//Khai bao thanh chan duoi cua cua so game
	x2.setFillColor(Color::Green);//Dat mau la xanh duong
	x2.setSize(Vector2f(20, 20));//Kich thuoc la 10x400
	x2.setPosition(50, 40);//Dat o vi tri (400;400) 
	x2.rotate(90);//Xoay thanh chan 90 do
	x2.setOutlineColor(Color::Cyan);

	RectangleShape x05;//Khai bao thanh chan duoi cua cua so game
	x05.setFillColor(Color::Yellow);//Dat mau la xanh duong
	x05.setSize(Vector2f(20, 20));//Kich thuoc la 10x400
	x05.setPosition(700, 70);//Dat o vi tri (400;400) 
	x05.rotate(90);//Xoay thanh chan 90 do
	x05.setOutlineColor(Color::Cyan);

	CircleShape end;//Khai bao thanh chan duoi cua cua so game
	end.setFillColor(Color::Red);//Dat mau cho qua bong la do
	end.setRadius(20);//Tao ban kinh qua bong la 10
	end.setPosition(200, 200);//Dat o vi tri (400;400) 
	end.rotate(90);//Xoay thanh chan 90 do
	end.setOutlineColor(Color::Cyan);

	RectangleShape vx2;//Khai bao thanh chan duoi cua cua so game
	vx2.setFillColor(Color::Blue);//Dat mau la xanh duong
	vx2.setSize(Vector2f(20, 20));//Kich thuoc la 10x400
	vx2.setPosition(300, 200);//Dat o vi tri (400;400) 
	vx2.rotate(90);//Xoay thanh chan 90 do
	vx2.setOutlineColor(Color::Cyan);

	RectangleShape vx05;//Khai bao thanh chan duoi cua cua so game
	vx05.setFillColor(Color::Blue);//Dat mau la xanh duong
	vx05.setSize(Vector2f(20, 20));//Kich thuoc la 10x400
	vx05.setPosition(300, 300);//Dat o vi tri (400;400) 
	vx05.rotate(90);//Xoay thanh chan 90 do
	vx05.setOutlineColor(Color::Cyan);
#pragma endregion
	
	Vector2 <float> BallSpeed(0.1, 0.1);//Tao cho bong di chuyen voi van toc (x, y) = (0.15, 0.15)

	while (Window.isOpen()) //Tien hanh chay game
	{
		Window.clear(Color::White);//Thiet lap nen game la mau trang
		Window.draw(BALL);//Tao doi tuong qua bong
		Window.draw(FirstPlayer);//Tao doi tuong nguoi choi thu 1
		Window.draw(SecondPlayer);//Tao doi tuong nguoi choi thu 2
		Window.draw(CanhDuoi);//Tao thanh san dau tren
		Window.draw(CanhTren);//Tao thanh san dau duoi
		Window.draw(BienTrai);//Tao gioi han trai
		Window.draw(BienPhai);//Tao gioi han phai
		Window.draw(x2);
		Window.draw(x05);
		Window.draw(end);
		Window.draw(vx2);
		Window.draw(vx05);

		Window.display();//Hien thi cac doi tuong da tao tren cua so game

		Event event;//Khoi tao bien chua cac su kien trong game
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();
		}
		
		//Tao thao tac cho nguoi choi
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			break;
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)) && (LimitPlayer(SecondPlayer, CanhTren) == false))
		{
			SecondPlayer.move(0, -0.1);
		}
		//Doi tuong secondPlayer se dich chuyen len tren voi van toc 0.1 neu nguoi choi bam phim mui ten len
		//va khong cham bien tren
		if ((Keyboard::isKeyPressed(Keyboard::Down)) && (LimitPlayer(SecondPlayer, CanhDuoi) == false))
		{
			SecondPlayer.move(0, 0.1);
		}
		//Doi tuong secondPlayer se dich chuyen xuong duoi voi van toc 0.1 neu nguoi choi bam phim mui ten xuong
		//va khong cham bien duoi
		if ((Keyboard::isKeyPressed(Keyboard::W)) && (LimitPlayer(FirstPlayer, CanhTren) == false))
		{
			FirstPlayer.move(0, -0.1);
		}
		//Doi tuong firstPlayer se dich chuyen len tren voi van toc 0.1 neu nguoi choi bam phim W
		//va khong cham bien tren
		if ((Keyboard::isKeyPressed(Keyboard::S)) && (LimitPlayer(FirstPlayer, CanhDuoi) == false))
		{
			FirstPlayer.move(0, 0.1);
		}
		//Doi tuong firstPlayer se dich chuyen len tren voi van toc 0.1 neu nguoi choi bam phim S
		//va khong cham bien duoi
		if (VaCham(BALL, BienTrai)) //Tao su kien bong cham gioi han trai
		{
			player2Score.score++;
			
			Window.draw(Player2Win);//Ve noi dung nguoi choi 2 thang
			Window.display();//Hien thi ra cua so
			main();
		}
		if (VaCham(BALL, BienPhai)) //Tao su kien bong cham gioi han phai
		{
			player2Score.score++;
			Window.draw(Player1Win);//Ve noi dung nguoi choi 1 thang
			Window.display();//Hien thi ra cua so
			main();
		}
		if (VaCham(BALL , CanhTren) || (VaCham(BALL, CanhDuoi)))//Xu li bong cham bien tren va duoi
		{
			BallSpeed.y = -BallSpeed.y;//Cho bong phan xa khi cham bien
		}
		if (VaCham(BALL, FirstPlayer) || (VaCham(BALL, SecondPlayer)))//Xu li bong cham nguoi choi
		{
			BallSpeed.x = -BallSpeed.x;//Cho bong phan xa khi cham nguoi choi
			BallSpeed.x += BallSpeed.x * 0.007;
			BallSpeed.y += BallSpeed.y * 0.007;
		}
		if (VaCham(BALL, x05))
		{
			BallSpeed.x += BallSpeed.x * 0.0007;
			BallSpeed.y += BallSpeed.y * 0.0007;
		}
		if (VaCham(BALL, x2))
		{
			BallSpeed.x += BallSpeed.x * 0.0207;
			BallSpeed.y += BallSpeed.y * 0.0207;
		}
		if (VaCham(BALL, vx05))
		{
			BallSpeed.x += BallSpeed.x * 0.0037;
			BallSpeed.y += BallSpeed.y * 0.0037;
		}
		if (VaCham(BALL, vx2))
		{
			BallSpeed.x += BallSpeed.x * 0.0307;
			BallSpeed.y += BallSpeed.y * 0.0307;
		}
		if (VaChamEnd(BALL, end))
		{
			main();
		}
		BALL.move(BallSpeed.x, BallSpeed.y);//Tra ve toc do ban dau cua bong
	}
	InKetQua(player1Score, player2Score);
}