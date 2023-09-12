#include "Rander.h"

extern Player player;
// extern Player player2;

void Rander()
{
	PrintDot(player);
	// PrintDot(player2);
	ObjectPool_Rander();
}

void ObjectPool_Rander()
{
	for (int i = 0; i < OBJECTPOOL_MAX; ++i)
	{
		if (objectPool[i].isAvailable == FALSE)
		{
			gotoxy(objectPool[i].centerPosition.x, objectPool[i].centerPosition.y);
		}
	}
}


void gotoxy(int x, int y)
{
	COORD pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf_s("@");
}

void 충돌메세지()
{
	COORD pos = { 190 , 5 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf_s("충돌!!!");
}


/*
void printCheck(int x, int y, Vector2D point)
{
	COORD pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf_s("%0.9lf, %0.9lf", point.x, point.y);
}
void printcccccc(Player player, Player player2)
{
	printCheck(150, 10, player.plgVertex[0]);
	printCheck(150, 11, player.plgVertex[1]);
	printCheck(150, 12, player.plgVertex[2]);
	printCheck(150, 13, player.plgVertex[3]);
	printCheck(150, 14, player.heightVector);

	printCheck(150, 16, player2.plgVertex[0]);
	printCheck(150, 17, player2.plgVertex[1]);
	printCheck(150, 18, player2.plgVertex[2]);
	printCheck(150, 19, player2.plgVertex[3]);
	printCheck(150, 20, player2.heightVector);
}
*/

void PrintDot(Player player)
{
	gotoxy(player.centerPosition.x, player.centerPosition.y);
	gotoxy(player.plgVertex[0].x, player.plgVertex[0].y);
	gotoxy(player.plgVertex[1].x, player.plgVertex[1].y);
	gotoxy(player.plgVertex[2].x, player.plgVertex[2].y);
	gotoxy(player.plgVertex[3].x, player.plgVertex[3].y);
}

/*
void printCir(Circle cl)
{
	gotoxy(cl.centerPosition.x, cl.centerPosition.y);
	gotoxy((cl.centerPosition.x - (cl.R / 2)), cl.centerPosition.y);
	gotoxy((cl.centerPosition.x + (cl.R / 2)), cl.centerPosition.y);
	gotoxy(cl.centerPosition.x, (cl.centerPosition.y - (cl.R / 2)));
	gotoxy(cl.centerPosition.x, (cl.centerPosition.y + (cl.R / 2)));
}
*/
