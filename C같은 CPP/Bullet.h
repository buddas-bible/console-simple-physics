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
	// �ҷ��� ��ġ
	Vector2D centerPosition;
	
	// Ȥ�� �� ���� �浹 ����� ���� ���� ��ǥ�� ����
	Vector2D prePosition;

	int radius;

	// �Ѿ��� �⺻ �ӷ�
	double speed;

	// ��庤��(���� ����) ��ġ���� �߻��Ѵٰ� �ϸ�.
	// ������Ʈ ������ �÷��̾� �Ǵ� ������ ��庤�� ��ġ���� ������ �ǰ�
	// �ӵ� = (��庤�� * �ӷ�)���� �ӵ� ���͸� ���ϸ� �� �Ͱ���. 
	Vector2D velocity;

	// �߻� �����Ѱ�?
	bool isAvailable;

}Bullet;


void ObjectPool_Init();
void Bullet_Init(Bullet* this, Player player);

int Bullet_GetBulletSpeed(int weaponNumber);
int Bullet_GetBulletRadius(int weaponNumber);

void Bullet_Shot(Player player);
void Bullet_Flying(Bullet* this, long long dt);
Bullet* Bullet_FindAvailableBullet();

