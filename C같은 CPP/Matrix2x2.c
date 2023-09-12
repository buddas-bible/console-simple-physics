#include "Matrix2x2.h"

Matrix2x2 Matrix2x2_Add(Matrix2x2 m1, Matrix2x2 m2)
{
	Matrix2x2 addResult;
	for (int y = 0; y < 2; ++y)
	{
		for (int x = 0; x < 2; ++x)
		{
			addResult.element[y][x] = m1.element[y][x] + m2.element[y][x];
		}
	}

	return addResult;
}

Matrix2x2 Matrix2x2_Sub(Matrix2x2 m1, Matrix2x2 m2)
{
	Matrix2x2 subResult;
	for (int y = 0; y < 2; ++y)
	{
		for (int x = 0; x < 2; ++x)
		{
			subResult.element[y][x] = m1.element[y][x] - m2.element[y][x];
		}
	}

	return subResult;
}

Matrix2x2 Matrix2x2_Mul(Matrix2x2 m1, Matrix2x2 m2)
{
	Matrix2x2 mulResult;

	mulResult.element[0][0] = (m1.element[0][0] * m2.element[0][0]) + (m1.element[0][1] * m2.element[1][0]);
	mulResult.element[0][1] = (m1.element[0][0] * m2.element[0][1]) + (m1.element[0][1] * m2.element[1][1]);
	mulResult.element[1][0] = (m1.element[1][0] * m2.element[0][0]) + (m1.element[1][1] * m2.element[1][0]);
	mulResult.element[1][1] = (m1.element[1][0] * m2.element[0][1]) + (m1.element[1][1] * m2.element[1][1]);

	return mulResult;
}

Matrix2x2 Matrix2x2_Set(double AA, double AB, double BA, double BB)
{
	Matrix2x2 setMatrix;

	setMatrix.element[0][0] = AA;
	setMatrix.element[0][1] = AB;
	setMatrix.element[1][0] = BA;
	setMatrix.element[1][1] = BB;

	return setMatrix;
}

Vector2D Metrix2x2_Vector(Matrix2x2 m1, Vector2D v1)
{
	Vector2D result;
	result.x = m1.element[0][0] * v1.x + m1.element[0][1] * v1.y;
	result.y = m1.element[1][0] * v1.x + m1.element[1][1] * v1.y;

	return result;
}