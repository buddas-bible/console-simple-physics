#pragma once
#include "Vector2D.h"

typedef struct
{
	double element[2][2];
}Matrix2x2;

Matrix2x2 Matrix2x2_Add(Matrix2x2 m1, Matrix2x2 m2);
Matrix2x2 Matrix2x2_Sub(Matrix2x2 m1, Matrix2x2 m2);
Matrix2x2 Matrix2x2_Mul(Matrix2x2 m1, Matrix2x2 m2);
Matrix2x2 Matrix2x2_Set(double AA, double AB, double BA, double BB);
Vector2D Metrix2x2_Vector(Matrix2x2 m1, Vector2D v1);