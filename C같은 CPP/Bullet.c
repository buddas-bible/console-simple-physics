#include "Bullet.h"


Bullet objectPool[OBJECTPOOL_MAX];


/// <summary>
/// 오브젝트 풀 초기화 함수
/// </summary>
void ObjectPool_Init()
{
	// 먼저 투사체들의 데이터를 전부 0으로 초기화 시켜준다.
	// 사용 가능 여부도 TRUE로 초기화 시켜둔다.
	for (int i = 0; i < OBJECTPOOL_MAX; ++i)
	{
		objectPool[i].centerPosition.x = 0;
		objectPool[i].centerPosition.y = 0;
		objectPool[i].prePosition.x = 0;
		objectPool[i].prePosition.y = 0;
		objectPool[i].speed = 0;
		objectPool[i].radius = 0;
		objectPool[i].isAvailable = TRUE;
	}
}

/// <summary>
/// 투사체를 초기화하는 함수
/// </summary>
/// <param name=""></param>
/// <param name="player"></param>
void Bullet_Init(Bullet* this, Player player)
{
	// 투사체의 위치를 옮긴다
	this->centerPosition = Vector2D_Add(player.centerPosition, Vector2D_Multiple(player.heightVector, player.radius));
	
	// 투사체의 속도를 초기화
	this->speed = Bullet_GetBulletSpeed(player.weaponNumber);

	// 투사체의 크기를 초기화
	this->radius = Bullet_GetBulletRadius(player.weaponNumber);

	// 투사체 속력
	this->velocity = Vector2D_Multiple(player.heightVector, this->speed);
}


/// <summary>
/// 플레이어의 무기에 따라 속도를 반환하는 함수
/// </summary>
/// <param name="weaponNumber">무기 번호</param>
/// <returns>투사체 속도</returns>
int Bullet_GetBulletSpeed(int weaponNumber)
{
	switch (weaponNumber)
	{
	case a:
		return SPEED_WEAPONa;

	case b:
		return SPEED_WEAPONb;

	case c:
		return SPEED_WEAPONb;

	default:
		break;
	}
}

/// <summary>
/// 플레이어의 무기에 따라 크기를 반환하는 함수
/// </summary>
/// <param name="weaponNumber">무기 번호</param>
/// <returns>투사체 크기</returns>
int Bullet_GetBulletRadius(int weaponNumber)
{
	switch (weaponNumber)
	{
	case a:
		return SPEED_WEAPONa;

	case b:
		return SPEED_WEAPONb;

	case c:
		return SPEED_WEAPONb;

	default:
		break;
	}
}


/// <summary>
/// 총을 쏘는 함수
/// </summary>
/// <param name="player"></param>
void Bullet_Shot(Player player)
{
	// 오브젝트 풀에서 사용가능한 투사체를 찾음
	Bullet* bullet = Bullet_FindAvailableBullet();

	// 투사체를 초기화
	Bullet_Init(bullet, player);

	// 사용 중 플래그
	bullet->isAvailable = FALSE;
}

/// <summary>
/// 델타타임마다 투사체가 이동하는 함수
/// </summary>
/// <param name="">투사체 포인터</param>
/// <param name="dt">델타타임</param>
void Bullet_Flying(Bullet* this, long long dt)
{
	this->centerPosition.x = this->centerPosition.x + (this->velocity.x * (dt / 1000.0));
	this->centerPosition.y = this->centerPosition.y + (this->velocity.y * (dt / 1000.0));
}


/// <summary>
/// 오브젝트 풀에서 사용 가능한 투사체를 반환하는 함수
/// </summary>
/// <returns>투사체의 포인터</returns>
Bullet* Bullet_FindAvailableBullet()
{
	for (int i = 0; i < OBJECTPOOL_MAX; ++i)
	{
		if (objectPool[i].isAvailable == TRUE)
		{
			Bullet* this = objectPool + i;

			return this;
		}
	}

	// 새로운 친구 생성 해야함.
}