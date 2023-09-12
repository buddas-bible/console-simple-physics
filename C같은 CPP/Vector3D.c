#include <math.h>

#include "Vector3D.h"
#include "game_Define.h"

double Vector3D_Size(Vector3D v1)
{
	double d = pow(pow(v1.x, 2.0) + pow(v1.y, 2.0) + pow(v1.z, 2.0), 0.5);

	return floor(d * 100000000000) / 100000000000;
}

/// <summary>
/// 벡터 더하기
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>두 벡터 합한 결과</returns>
Vector3D Vector3D_Add(Vector3D v1, Vector3D v2)
{
	Vector3D addResult = { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };

	return addResult;
}

/// <summary>
/// 벡터 빼기
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>두 벡터 뺀 결과</returns>
Vector3D Vector3D_Sub(Vector3D v1, Vector3D v2)
{
	Vector3D subResult = { v1.x - v2.x , v1.y - v2.y, v1.z - v2.z };

	return subResult;
}

/// <summary>
/// 벡터 실수배
/// </summary>
/// <param name="v1"></param>
/// <param name="R"></param>
/// <returns>실수배 벡터</returns>
Vector3D Vector3D_Multiple(Vector3D v1, double R)
{
	v1.x = v1.x * R;
	v1.y = v1.y * R;
	v1.z = v1.z * R;

	return v1;
}

/// <summary>
/// 벡터 내적
/// </summary>
/// <param name="v1">벡터</param>
/// <param name="v2">벡터</param>
/// <returns>-1 ~ 1 사이 cos theta 값</returns>
double Vector3D_Dot(Vector3D v1, Vector3D v2)
{
	double dotResult = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

	return dotResult;
}

/// <summary>
/// 벡터 외적
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>외적 벡터</returns>
Vector3D Vector3D_Cross(Vector3D v1, Vector3D v2)
{
	Vector3D crossResult = { ((v1.y * v2.z) - (v1.z * v2.y)), 
							((v1.z * v2.x) - (v1.x * v2.z)), 
							(v1.x * v2.y) - (v1.y * v2.x)};

	return crossResult;
}

/// <summary>
/// 두 벡터 사이 각도를 구하는 함수
/// </summary>
/// <param name="v1">벡터</param>
/// <param name="v2">벡터</param>
/// <returns>theta</returns>
double Vector3D_FindTheta(Vector3D v1, Vector3D v2)
{
	v1 = Vector3D_Normalization(v1);
	v2 = Vector3D_Normalization(v2);

	double dot = Vector3D_Dot(v1, v2);

	if (dot > 1.0)
	{
		dot = 1.0;
	}
	if (dot < -1.0)
	{
		dot = -1.0;
	}

	return acos(dot);
}

/// <summary>
/// 벡터 정규화
/// </summary>
/// <param name="v1">벡터</param>
/// <returns>정규화된 벡터</returns>
Vector3D Vector3D_Normalization(Vector3D v1)
{
	Vector3D result = 
	{ 
		v1.x / Vector3D_Size(v1), 
		v1.y / Vector3D_Size(v1), 
		v1.z / Vector3D_Size(v1) 
	};

	return result;
}

/// <summary>
/// 두 벡터 크기 비교
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>v2가 크면 1, 아니면 0</returns>
double Vector3D_BiggerThen(Vector3D v1, Vector3D v2)
{
	if ((v1.x < v2.x) && (v1.y < v2.y) && (v1.z < v2.z))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/// <summary>
/// 두 벡터가 같은지 확인하고 1또는 0을 리턴
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>같으면 1, 아니면 0</returns>
double Vector3D_Equality(Vector3D v1, Vector3D v2)
{
	if ((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}