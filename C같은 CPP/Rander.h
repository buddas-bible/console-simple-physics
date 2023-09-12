#pragma once
#include "Vector2D.h"
#include "Player.h"
#include "Bullet.h"
#include "Circle.h"
#include "Rander.h"
#include "game_Define.h"

extern Bullet objectPool[OBJECTPOOL_MAX];

void Rander();

void ObjectPool_Rander();

void gotoxy(int x, int y);
void 충돌메세지();

// void printCheck(int x, int y, Vector2D point);
// void printcccccc(Player, Player);
// void printCir(Circle cl);

void PrintDot(Player);
void printManager(Player, Player);

void PlayerMove(Player* player, Vector2D point);
