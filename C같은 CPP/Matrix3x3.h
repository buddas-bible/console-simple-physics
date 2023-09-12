#pragma once
#include "Vector3D.h"

typedef struct
{
	double element[3][3];
}Matrix3x3;

Matrix3x3 Matrix3x3_Add(Matrix3x3 m1, Matrix3x3 m2);
Matrix3x3 Matrix3x3_Sub(Matrix3x3 m1, Matrix3x3 m2);
Matrix3x3 Matrix3x3_Mul(Matrix3x3 m1, Matrix3x3 m2);
