#include <math.h>

#include "Vector3D.h"
#include "game_Define.h"

double Vector3D_Size(Vector3D v1)
{
	double d = pow(pow(v1.x, 2.0) + pow(v1.y, 2.0) + pow(v1.z, 2.0), 0.5);

	return floor(d * 100000000000) / 100000000000;
}

/// <summary>
/// ���� ���ϱ�
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>�� ���� ���� ���</returns>
Vector3D Vector3D_Add(Vector3D v1, Vector3D v2)
{
	Vector3D addResult = { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };

	return addResult;
}

/// <summary>
/// ���� ����
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>�� ���� �� ���</returns>
Vector3D Vector3D_Sub(Vector3D v1, Vector3D v2)
{
	Vector3D subResult = { v1.x - v2.x , v1.y - v2.y, v1.z - v2.z };

	return subResult;
}

/// <summary>
/// ���� �Ǽ���
/// </summary>
/// <param name="v1"></param>
/// <param name="R"></param>
/// <returns>�Ǽ��� ����</returns>
Vector3D Vector3D_Multiple(Vector3D v1, double R)
{
	v1.x = v1.x * R;
	v1.y = v1.y * R;
	v1.z = v1.z * R;

	return v1;
}

/// <summary>
/// ���� ����
/// </summary>
/// <param name="v1">����</param>
/// <param name="v2">����</param>
/// <returns>-1 ~ 1 ���� cos theta ��</returns>
double Vector3D_Dot(Vector3D v1, Vector3D v2)
{
	double dotResult = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

	return dotResult;
}

/// <summary>
/// ���� ����
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>���� ����</returns>
Vector3D Vector3D_Cross(Vector3D v1, Vector3D v2)
{
	Vector3D crossResult = { ((v1.y * v2.z) - (v1.z * v2.y)), 
							((v1.z * v2.x) - (v1.x * v2.z)), 
							(v1.x * v2.y) - (v1.y * v2.x)};

	return crossResult;
}

/// <summary>
/// �� ���� ���� ������ ���ϴ� �Լ�
/// </summary>
/// <param name="v1">����</param>
/// <param name="v2">����</param>
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
/// ���� ����ȭ
/// </summary>
/// <param name="v1">����</param>
/// <returns>����ȭ�� ����</returns>
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
/// �� ���� ũ�� ��
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>v2�� ũ�� 1, �ƴϸ� 0</returns>
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
/// �� ���Ͱ� ������ Ȯ���ϰ� 1�Ǵ� 0�� ����
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>������ 1, �ƴϸ� 0</returns>
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