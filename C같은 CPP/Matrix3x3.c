#include "Matrix3x3.h"


Matrix3x3 Matrix3x3_Add(Matrix3x3 m1, Matrix3x3 m2)
{
	Matrix3x3 addResult;
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			addResult.element[y][x] = m1.element[y][x] + m2.element[y][x];
		}
	}

	return addResult;
}

Matrix3x3 Matrix3x3_Sub(Matrix3x3 m1, Matrix3x3 m2)
{
	Matrix3x3 subResult;
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			subResult.element[y][x] = m1.element[y][x] - m2.element[y][x];
		}
	}

	return subResult;
}

Matrix3x3 Matrix3x3_Mul(Matrix3x3 m1, Matrix3x3 m2)
{
	Matrix3x3 mulResult;

	mulResult.element[0][0] =
		(m1.element[0][0] * m2.element[0][0]) + 
		(m1.element[0][1] * m2.element[1][0]) + 
		(m1.element[0][2] * m2.element[2][0]);

	mulResult.element[0][1] = 
		(m1.element[0][0] * m2.element[0][1]) + 
		(m1.element[0][1] * m2.element[1][1]) +
		(m1.element[0][2] * m2.element[2][1]);
	
	mulResult.element[0][2] =
		(m1.element[0][0] * m2.element[0][2]) +
		(m1.element[0][1] * m2.element[1][2]) +
		(m1.element[0][2] * m2.element[2][2]);


	mulResult.element[1][0] =
		(m1.element[1][0] * m2.element[0][0]) +
		(m1.element[1][1] * m2.element[1][0]) +
		(m1.element[1][2] * m2.element[2][0]);

	mulResult.element[1][1] =
		(m1.element[1][0] * m2.element[0][1]) +
		(m1.element[1][1] * m2.element[1][1]) +
		(m1.element[1][2] * m2.element[2][1]);

	mulResult.element[1][2] =
		(m1.element[1][0] * m2.element[0][2]) +
		(m1.element[1][1] * m2.element[1][2]) +
		(m1.element[1][2] * m2.element[2][2]);

	
	mulResult.element[2][0] =
		(m1.element[2][0] * m2.element[0][0]) +
		(m1.element[2][1] * m2.element[1][0]) +
		(m1.element[2][2] * m2.element[2][0]);

	mulResult.element[2][1] =
		(m1.element[2][0] * m2.element[0][1]) +
		(m1.element[2][1] * m2.element[1][1]) +
		(m1.element[2][2] * m2.element[2][1]);

	mulResult.element[2][2] =
		(m1.element[2][0] * m2.element[0][2]) +
		(m1.element[2][1] * m2.element[1][2]) +
		(m1.element[2][2] * m2.element[2][2]);
	
	return mulResult;
}

