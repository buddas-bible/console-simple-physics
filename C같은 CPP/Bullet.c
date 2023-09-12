#include "Bullet.h"


Bullet objectPool[OBJECTPOOL_MAX];


/// <summary>
/// ������Ʈ Ǯ �ʱ�ȭ �Լ�
/// </summary>
void ObjectPool_Init()
{
	// ���� ����ü���� �����͸� ���� 0���� �ʱ�ȭ �����ش�.
	// ��� ���� ���ε� TRUE�� �ʱ�ȭ ���ѵд�.
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
/// ����ü�� �ʱ�ȭ�ϴ� �Լ�
/// </summary>
/// <param name=""></param>
/// <param name="player"></param>
void Bullet_Init(Bullet* this, Player player)
{
	// ����ü�� ��ġ�� �ű��
	this->centerPosition = Vector2D_Add(player.centerPosition, Vector2D_Multiple(player.heightVector, player.radius));
	
	// ����ü�� �ӵ��� �ʱ�ȭ
	this->speed = Bullet_GetBulletSpeed(player.weaponNumber);

	// ����ü�� ũ�⸦ �ʱ�ȭ
	this->radius = Bullet_GetBulletRadius(player.weaponNumber);

	// ����ü �ӷ�
	this->velocity = Vector2D_Multiple(player.heightVector, this->speed);
}


/// <summary>
/// �÷��̾��� ���⿡ ���� �ӵ��� ��ȯ�ϴ� �Լ�
/// </summary>
/// <param name="weaponNumber">���� ��ȣ</param>
/// <returns>����ü �ӵ�</returns>
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
/// �÷��̾��� ���⿡ ���� ũ�⸦ ��ȯ�ϴ� �Լ�
/// </summary>
/// <param name="weaponNumber">���� ��ȣ</param>
/// <returns>����ü ũ��</returns>
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
/// ���� ��� �Լ�
/// </summary>
/// <param name="player"></param>
void Bullet_Shot(Player player)
{
	// ������Ʈ Ǯ���� ��밡���� ����ü�� ã��
	Bullet* bullet = Bullet_FindAvailableBullet();

	// ����ü�� �ʱ�ȭ
	Bullet_Init(bullet, player);

	// ��� �� �÷���
	bullet->isAvailable = FALSE;
}

/// <summary>
/// ��ŸŸ�Ӹ��� ����ü�� �̵��ϴ� �Լ�
/// </summary>
/// <param name="">����ü ������</param>
/// <param name="dt">��ŸŸ��</param>
void Bullet_Flying(Bullet* this, long long dt)
{
	this->centerPosition.x = this->centerPosition.x + (this->velocity.x * (dt / 1000.0));
	this->centerPosition.y = this->centerPosition.y + (this->velocity.y * (dt / 1000.0));
}


/// <summary>
/// ������Ʈ Ǯ���� ��� ������ ����ü�� ��ȯ�ϴ� �Լ�
/// </summary>
/// <returns>����ü�� ������</returns>
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

	// ���ο� ģ�� ���� �ؾ���.
}