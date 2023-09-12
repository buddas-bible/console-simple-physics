#pragma once
#include "game_Define.h"
#include "Vector2D.h"
#include "Player.h"

#define OBJECTPOOL_MAX 50
#define SPEED_WEAPONa 1
#define SPEED_WEAPONb 10
#define SPEED_WEAPONc 10
#define SPEED_WEAPONd 15
#define SPEED_WEAPONe 20
#define SPEED_WEAPONf 30
#define SPEED_WEAPONg 40
#define SPEED_WEAPONh 50


typedef struct
{
	// 불렛의 위치
	Vector2D centerPosition;
	
	// 혹시 모를 선분 충돌 계산을 위해 이전 좌표를 저장
	Vector2D prePosition;

	int radius;

	// 총알의 기본 속력
	double speed;

	// 헤드벡터(높이 벡터) 위치에서 발사한다고 하면.
	// 오브젝트 생성을 플레이어 또는 적군의 헤드벡터 위치에서 생성이 되고
	// 속도 = (헤드벡터 * 속력)으로 속도 벡터를 구하면 될 것같다. 
	Vector2D velocity;

	// 발사 가능한가?
	bool isAvailable;

}Bullet;


void ObjectPool_Init();
void Bullet_Init(Bullet* this, Player player);

int Bullet_GetBulletSpeed(int weaponNumber);
int Bullet_GetBulletRadius(int weaponNumber);

void Bullet_Shot(Player player);
void Bullet_Flying(Bullet* this, long long dt);
Bullet* Bullet_FindAvailableBullet();

