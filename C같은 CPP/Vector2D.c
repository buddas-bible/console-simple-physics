#include <windows.h>
#include <math.h>

#include "Vector2D.h"
#include "game_Define.h"



/// <summary>
/// ���� ũ�� ���ϱ�
/// </summary>
/// <param name="v1">����</param>
/// <returns>���� ũ��</returns>
double Vector2D_Size(Vector2D v1)
{
	double x = pow(v1.x, 2.0);
	double y = pow(v1.y, 2.0);
	double d = pow(x + y, 0.5);

	return floor(d * 100000000000) / 100000000000;
}

/// <summary>
/// ���� ���ϱ�
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>�� ���� ���� ���</returns>
Vector2D Vector2D_Add(Vector2D v1, Vector2D v2)
{
	Vector2D AddResult = { v1.x + v2.x , v1.y + v2.y };

	return AddResult;
}

/// <summary>
/// ���� ����
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>�� ���� �� ���</returns>
Vector2D Vector2D_Sub(Vector2D v1, Vector2D v2)
{
	Vector2D SubResult = { v1.x - v2.x , v1.y - v2.y };

	return SubResult;
}

/// <summary>
/// ���� �Ǽ���
/// </summary>
/// <param name="v1"></param>
/// <param name="R"></param>
/// <returns>�Ǽ��� ����</returns>
Vector2D Vector2D_Multiple(Vector2D v1, double R)
{
	v1.x = v1.x * R;
	v1.y = v1.y * R;

	return v1;
}

/// <summary>
/// ���� ����
/// </summary>
/// <param name="v1">����</param>
/// <param name="v2">����</param>
/// <returns>-1 ~ 1 ���� cos theta ��</returns>
double Vector2D_Dot(Vector2D v1, Vector2D v2)
{
	double DotResult = (v1.x * v2.x) + (v1.y * v2.y);

	return DotResult;
}

/// <summary>
/// ���� ����
/// 2D ��� �󿡼� ������ x,y���� 0. Z���� ����
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>Z��</returns>
double Vector2D_Cross(Vector2D v1, Vector2D v2)
{
	double CrossResult = (v1.x * v2.y) - (v2.x * v1.y);
	
	return CrossResult;
}

/// <summary>
/// ���ʺй��� ȣ�������� ��ȯ���ִ� �Լ�
/// </summary>
/// <param name="deg">���ʺй�</param>
/// <returns>ȣ����</returns>
double DegToRadian(double deg)
{
	return deg / 180 * PI;
}

/// <summary>
/// �� ���� ���� ������ ���ϴ� �Լ�
/// </summary>
/// <param name="v1">����</param>
/// <param name="v2">����</param>
/// <returns>theta</returns>
double Vector2D_FindTheta(Vector2D v1, Vector2D v2)
{
	v1 = Vector2D_Normalization(v1);
	v2 = Vector2D_Normalization(v2);

	// ������ ���Ѵ�.
	double dot = Vector2D_Dot(v1, v2);

	if (dot > 1.0)
	{
		dot = 1.0;
	}
	if (dot < -1.0)
	{
		dot = -1.0;
	}
	// ������ �̿��� ���� ���
	// V1, V2 ������ = |V1||V2|cos(theta)
	// double vector1 = Vector2D_Size(v1);
	// double vector2 = Vector2D_Size(v2);
	// cos(theta) = (V1 dot V2) / |V1| |V2|
	// theta = acos((V1 dot V2) / |V1| |V2|)
	return acos(dot);
}

/// <summary>
/// v1�� ����ȭ�� ���� v2�� ������Ű�� �Լ�.
/// </summary>
/// <param name="v1">���� 1</param>
/// <param name="v2">���� 2</param>
/// <returns>������ ���� ũ��</returns>
double Vector2D_ScalarProjection(Vector2D v1, Vector2D v2)
{
	double result;
	v2 = Vector2D_Normalization(v2);
	
	result = Vector2D_Dot(v1, v2);

	return fabs(result);
}



/// <summary>
/// ���� ����ȭ
/// </summary>
/// <param name="v1">����</param>
/// <returns>����ȭ�� ����</returns>
Vector2D Vector2D_Normalization(Vector2D v1)
{
	Vector2D result = 
	{
		v1.x / Vector2D_Size(v1), 
		v1.y / Vector2D_Size(v1)
	};

	return result;
}

/// <summary>
/// �� ���� ũ�� ��
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns>v2�� ũ�� 1, �ƴϸ� 0</returns>
double Vector2D_BiggerThen(Vector2D v1, Vector2D v2)
{
	if ((v1.x < v2.x) && (v1.y < v2.y))
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
double Vector2D_Equality(Vector2D v1, Vector2D v2)
{
	if ((v1.x == v2.x) && (v1.y == v2.y))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}