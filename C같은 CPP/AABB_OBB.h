#pragma once

#include "Vector2D.h"

#include "Player.h"
#include "Circle.h"
#include "Bullet.h"


bool CollisionCheck_RtoP(RECT A, Vector2D B);
bool CollisionCheck_CtoP(Bullet A, Vector2D B);

bool CollisionCheck_AABB(RECT A, RECT B);

bool CollisionCheck_OBB(Player A, Player B);

bool CollisionCheck_OBB2(Player A, Bullet B);

bool CollisionCheck_CtoC(Bullet A, Bullet B);
bool CollisionCheck_BtoC(Bullet A, RECT B);