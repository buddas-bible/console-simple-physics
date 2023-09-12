#pragma once
#include "windows.h"

#include "Vector2D.h"

typedef struct
{
	int HP;

	// 위치
	Vector2D centerPosition;

	// 헤드 벡터
	Vector2D heightVector;
	Vector2D widthVector;

	// 크기
	int radius;

	int weaponNumber;

	// 이전 위치
	Vector2D prePosition;

	// 연산에 쓰는 버텍스 좌표
	Vector2D plgVertex[4];
	POINT a[3];

}Player;