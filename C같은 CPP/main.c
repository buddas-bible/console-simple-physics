#include <stdio.h>
#include <windows.h>
#include <math.h>

#include "Rander.h"

#include "game_Define.h"
#include "LineSegment.h"
#include "AABB_OBB.h"

#include "Vector2D.h"
#include "Rotation.h"

#include "Circle.h"
#include "Player.h"
#include "Bullet.h"

Player player;
Player player2;

RECT rect[4];

extern Bullet objectPool[OBJECTPOOL_MAX];

/*
RECT AA;
RECT BB;
Circle circle;
Circle circle2;
*/

void rectA_Up(RECT* rc);
void rectA_Down(RECT* rc);
void rectA_Left(RECT* rc);
void rectA_Right(RECT* rc);

void CircleA_Up(Circle* cl);
void CircleA_Down(Circle* cl);
void CircleA_Left(Circle* cl);
void CircleA_Right(Circle* cl);

void RectInit(RECT* rect, int l, int t, int r, int b)
{
	rect->left = l;
	rect->top = t;
	rect->right = r;
	rect->bottom = b;
}

void PlayerInit(Player* player, double x, double y, int radius, double theta, int weapon)
{
	player->centerPosition.x = x;
	player->centerPosition.y = y;
	player->radius = radius;

	player->heightVector.x = 0;
	player->heightVector.y = -1;
	player->widthVector.x = 1;
	player->widthVector.y = 0;

	player->weaponNumber = weapon;

	player->plgVertex[0].x = player->centerPosition.x - player->radius;
	player->plgVertex[0].y = player->centerPosition.y - player->radius;

	player->plgVertex[1].x = player->centerPosition.x + player->radius;
	player->plgVertex[1].y = player->centerPosition.y - player->radius;

	player->plgVertex[2].x = player->centerPosition.x - player->radius;
	player->plgVertex[2].y = player->centerPosition.y + player->radius;

	player->plgVertex[3].x = player->centerPosition.x + player->radius;
	player->plgVertex[3].y = player->centerPosition.y + player->radius;

	Rotation_PlayerRotation(player, theta);
}

void printCheck2()
{
	COORD pos = { 170 , 5 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf_s("충돌했습니다!!!!");
}

void PlayerMove(Player* player, Vector2D point)
{
	player->centerPosition.x += point.x;
	player->centerPosition.y += point.y;

	player->plgVertex[0].x += point.x;
	player->plgVertex[0].y += point.y;

	player->plgVertex[1].x += point.x;
	player->plgVertex[1].y += point.y;

	player->plgVertex[2].x += point.x;
	player->plgVertex[2].y += point.y;

	player->plgVertex[3].x += point.x;
	player->plgVertex[3].y += point.y;
}

void PlayerMoveFunc()
{
	bool keypressedUp = GetAsyncKeyState(VK_UP);// &0x0001;
	bool keypressedDown = GetAsyncKeyState(VK_DOWN);// &0x0001;
	bool keypressedLeft = GetAsyncKeyState(VK_LEFT);// &0x0001;
	bool keypressedRight = GetAsyncKeyState(VK_RIGHT);// &0x0001;
	bool keypressedSpace = GetAsyncKeyState(VK_SPACE) & 0x0001;
	bool keypressedNum4 = GetAsyncKeyState(VK_MBUTTON);// &0x0001;
	bool keypressedNum6 = GetAsyncKeyState(VK_RBUTTON);// &0x0001;

	Vector2D UP = { 0.0, -1.0 };
	Vector2D DOWN = { 0.0, 1.0 };
	Vector2D LEFT = { -1.0, 0.0 };
	Vector2D RIGHT = { 1.0, 0.0 };

	if (keypressedUp)
	{
		PlayerMove(&player, UP);
	}

	if (keypressedDown)
	{
		PlayerMove(&player, DOWN);
	}

	if (keypressedLeft)
	{
		PlayerMove(&player, LEFT);
	}

	if (keypressedRight)
	{
		PlayerMove(&player, RIGHT);
	}

	if (keypressedSpace)
	{
		Bullet_Shot(player);
	}

	if (keypressedNum4)
	{
		Rotation_PlayerRotation(&player, -(PI / 36));
	}

	if (keypressedNum6)
	{
		Rotation_PlayerRotation(&player, PI / 36);
	}
}

int main()
{
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	system("mode con: cols=200 lines=70 | title Dot Run!!");
	
	// init
	ObjectPool_Init();
	PlayerInit(&player, 20.0, 20.0, 5, PI / 4, 2);
	// PlayerInit(&player2, 50.0, 20.0, 5, PI / 5, 2);
	Vector2D Mouse = { 50.0, 50.0 };
	
	RectInit(&rect[0], 0, 0, 200, 10);
	RectInit(&rect[1], 0, 0, 10, 70);
	RectInit(&rect[2], 70, 0, 90, 70);
	RectInit(&rect[3], 0, 60, 200, 70);

	time_t lastframe = clock();
	int state = 1; 
	while (state)
	{
		time_t deltaTime = clock() - lastframe;
		lastframe = clock();

		system("cls");


		// 행동
		PlayerMoveFunc();
		for (int i = 0; i < OBJECTPOOL_MAX; i++)
		{
			if (objectPool[i].isAvailable == FALSE)
			{
				Bullet_Flying(objectPool + i, deltaTime);
			}
		}



		// 체크
		for (int j = 0; j < 4; ++j)
		{
			for (int i = 0; i < OBJECTPOOL_MAX; i++)
			{
				if (objectPool[i].isAvailable == FALSE)
				{						
					if (CollisionCheck_BtoC(objectPool[i], rect[j]) == TRUE)
					{	
						충돌메세지();
						objectPool[i].isAvailable = TRUE;
					}
				}
			}
		}

		// 이벤트




		// 그리기
		Rander();


		
		/*
		gotoxy(Mouse.x, Mouse.y);
		gotoxy(player.centerPosition.x + player.heightVector.x, player.centerPosition.y + player.heightVector.y);
		


		if (CollisionCheck_OBB(player, player2))
		{
			printCheck2();
		}
		*/
	}
	return 0;
}

void rectA_Up(RECT* rc)
{
	rc->top -= 1;
	rc->bottom -= 1;
}

void rectA_Down(RECT* rc)
{
	rc->top += 1;
	rc->bottom += 1;
}

void rectA_Left(RECT* rc)
{
	rc->left -= 1;
	rc->right -= 1;
}

void rectA_Right(RECT* rc)
{
	rc->left += 1;
	rc->right += 1;
}


void CircleA_Up(Circle* cl)
{
	cl->centerPosition.y -= 1;
}

void CircleA_Down(Circle* cl)
{
	cl->centerPosition.y += 1;
}

void CircleA_Left(Circle* cl)
{
	cl->centerPosition.x -= 1;
}

void CircleA_Right(Circle* cl)
{
	cl->centerPosition.x += 1;
}