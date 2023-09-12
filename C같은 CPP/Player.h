#pragma once
#include "windows.h"

#include "Vector2D.h"

typedef struct
{
	int HP;

	// ��ġ
	Vector2D centerPosition;

	// ��� ����
	Vector2D heightVector;
	Vector2D widthVector;

	// ũ��
	int radius;

	int weaponNumber;

	// ���� ��ġ
	Vector2D prePosition;

	// ���꿡 ���� ���ؽ� ��ǥ
	Vector2D plgVertex[4];
	POINT a[3];

}Player;