#include <math.h>
#include <windows.h>

#include "game_Define.h"
#include "Rotation.h"
#include "AABB_OBB.h"


/// <summary>
/// �ڽ��� �� ��
/// </summary>
/// <param name="A">�ڽ�</param>
/// <param name="B">��</param>
/// <returns>�ڽ� �ȿ� ���� ������ true</returns>
bool CollisionCheck_RtoP(RECT A, Vector2D B)
{
	if (((A.left <= B.x) && (B.x <= A.right)) && 
		((A.top <= B.y) && (B.y <= A.bottom)))
	{
		return TRUE;
	}

	return FALSE;
}

/// <summary>
/// ���� �� ��
/// </summary>
/// <param name="A">��</param>
/// <param name="B">��</param>
/// <returns>�� �ȿ� ���� ������ true</returns>
bool CollisionCheck_CtoP(Bullet A, Vector2D B)
{
	double x = pow(fabs(A.centerPosition.x - B.x), 2.0);
	double y = pow(fabs(A.centerPosition.y - B.y), 2.0);

	double d = sqrt(x + y);

	int r = A.radius / 2;

	if (r < d)
	{
		return FALSE;
	}

	return TRUE;
}

/// <summary>
/// �� �ڽ� ��
/// </summary>
/// <param name="A">�ڽ�1 (�»�,���� ���� ������ �ִ� ����ü)</param>
/// <param name="B">�ڽ�2 (�»�,���� ���� ������ �ִ� ����ü)</param>
/// <returns>��ġ�� true</returns>
bool CollisionCheck_AABB(RECT A, RECT B)
{
	if (A.right < B.left || A.left > B.right)
	{
		return FALSE;
	}

	if (A.top > B.bottom || A.bottom < B.top)
	{
		return FALSE;
	}

	return TRUE;
}

/// <summary>
/// ���� �и��� �ڽ� 2�� ��
/// 
/// ������δ� ������ �� ���͸� ���ؾ�������
/// �簢�������� �浹�̱� ������ ���簢������ �� ���� �����ϱ� ������
/// �ʺ�� ���� ���͸� �̿��ߴ�.
/// </summary>
/// <param name="A">������, 4���� �𼭸�, ���� ���Ϳ� �ʺ� ���͸� ���� �簢��</param>
/// <param name="B">������, 4���� �𼭸�, ���� ���Ϳ� �ʺ� ���͸� ���� �簢��</param>
/// <returns>��ġ�� true</returns>
bool CollisionCheck_OBB(Player A, Player B)
{
	// �� ��ü ���� ���� (B -> A)
	Vector2D d = Vector2D_Sub(A.centerPosition, B.centerPosition);
	Vector2D aVec[2] = { A.widthVector, A.heightVector};
	Vector2D bVec[2] = { B.widthVector, B.heightVector };

	Vector2D aVertex1 = Vector2D_Sub(A.plgVertex[0], A.centerPosition);
	Vector2D bVertex1 = Vector2D_Sub(B.plgVertex[0], B.centerPosition);

	for (int i = 0; i < 2; ++i)
	{
		double sum = 0;

		// ��ü �������� �𼭸��� ����Ű�� ���͸� ������Ų��.
		double vertexScalar = Vector2D_ScalarProjection(aVertex1, aVec[i]);

		sum = sum + vertexScalar;

		// �𼭸� ���͸� ������ ��ü�� ���� ����, �ʺ� ���Ϳ� ������Ű��,
		// ����ȭ �ؼ� �ٸ� ��ü�� ���̽� ���Ϳ� ������Ų��.
		for (int j = 0; j < 2; ++j)
		{
			// �𼭸� ���͸� �ڽ��� �ʺ�, ���� ���Ϳ� ������Ų��.
			double Scalar = Vector2D_ScalarProjection(bVertex1, bVec[j]);
			
			Scalar = floor(Scalar * 100000000000) / 100000000000;

			// �������� ���� ��Į�� ���� ���̽� ���Ϳ� ���ؼ� ���͸� ���Ѵ�.
			Vector2D vector = Vector2D_Multiple(bVec[j], Scalar);

			// ���� ���͸� ���̽� ���Ϳ� ������Ų��.
			double baseTovector = Vector2D_ScalarProjection(vector, aVec[i]);

			sum = sum + baseTovector;
		}

		double dScalar = Vector2D_ScalarProjection(d, aVec[i]);
		if (sum < dScalar)
		{
			return FALSE;
		}
	}

	for (int i = 0; i < 2; ++i)
	{
		double sum = 0;

		// ��ü �������� �𼭸��� ����Ű�� ���͸� ������Ų��
		double vertexScalar = Vector2D_ScalarProjection(bVertex1, bVec[i]);

		sum = sum + vertexScalar;

		// �𼭸� ���͸� ������ ��ü�� ���� ����, �ʺ� ���Ϳ� ������Ű��,
		// ����ȭ �ؼ� �ٸ� ��ü�� ���̽� ���Ϳ� ������Ų��.
		for (int j = 0; j < 2; ++j)
		{
			// �𼭸� ���͸� �ڽ��� �ʺ�, ���� ���Ϳ� ������Ų��.
			double Scalar = Vector2D_ScalarProjection(aVertex1, aVec[j]);

			Scalar = floor(Scalar * 100000000000) / 100000000000;

			// �������� ���� ��Į�� ���� ���̽� ���Ϳ� ���ؼ� ���͸� ���Ѵ�.
			Vector2D vector = Vector2D_Multiple(aVec[j], Scalar);

			// ���� ���͸� ���̽� ���Ϳ� ������Ų��.
			double baseTovector = Vector2D_ScalarProjection(vector, bVec[i]);

			sum = sum + baseTovector;
		}

		double dScalar = Vector2D_ScalarProjection(d, bVec[i]);
		if (sum < dScalar)
		{
			return FALSE;
		}
	}

	return TRUE;
}

/// <summary>
/// ���� �и��� �ڽ��� �� ��
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <returns></returns>
bool CollisionCheck_OBB2(Player A, Bullet B)
{
	// �� ��ü ���� ���� (B -> A)
	Vector2D d = Vector2D_Sub(A.centerPosition, B.centerPosition);
	Vector2D aVec[2] = { A.widthVector, A.heightVector };
	Vector2D bVec[2] = { { 1 , 0 }, { 0 , -1 } };

	Vector2D circleRadius = {0, B.radius};

	Vector2D aVertex1 = Vector2D_Sub(A.plgVertex[0], A.centerPosition);
	// Vector2D bVertex1 = Vector2D_Sub(Vector2D_Add(), B.centerPosition);

	for (int i = 0; i < 2; ++i)
	{
		double sum = 0;

		// ��ü �������� �𼭸��� ����Ű�� ���͸� ������Ų��.
		double vertexScalar = Vector2D_ScalarProjection(aVertex1, aVec[i]);

		sum = sum + vertexScalar;

		sum = sum + B.radius;

		double dScalar = Vector2D_ScalarProjection(d, aVec[i]);
		if (sum < dScalar)
		{
			return FALSE;
		}
	}

	for (int i = 0; i < 2; ++i)
	{
		double sum = 0;

		sum = sum + B.radius;

		// �𼭸� ���͸� ������ ��ü�� ���� ����, �ʺ� ���Ϳ� ������Ű��,
		// ����ȭ �ؼ� �ٸ� ��ü�� ���̽� ���Ϳ� ������Ų��.
		for (int j = 0; j < 2; ++j)
		{
			// �𼭸� ���͸� �ڽ��� �ʺ�, ���� ���Ϳ� ������Ų��.
			double Scalar = Vector2D_ScalarProjection(aVertex1, aVec[j]);

			Scalar = floor(Scalar * 100000000000) / 100000000000;

			// �������� ���� ��Į�� ���� ���̽� ���Ϳ� ���ؼ� ���͸� ���Ѵ�.
			Vector2D vector = Vector2D_Multiple(aVec[j], Scalar);

			// ���� ���͸� ���̽� ���Ϳ� ������Ų��.
			double baseTovector = Vector2D_ScalarProjection(vector, bVec[i]);

			sum = sum + baseTovector;
		}

		double dScalar = Vector2D_ScalarProjection(d, bVec[i]);
		if (sum < dScalar)
		{
			return FALSE;
		}
	}

	return TRUE;
}

/// <summary>
/// �� �� �浹
/// �浹 ó���� ����� �̷����� �ʴ´ٸ�
/// math.h�� Ȯ������
/// </summary>
/// <param name="A">��1 (������ ������ ������ �ִ� ����ü)</param>
/// <param name="B">��2 (������ ������ ������ �ִ� ����ü)</param>
/// <returns>��ġ�� true</returns>
bool CollisionCheck_CtoC(Bullet A, Bullet B)
{
	// ���� �Լ� (���� �Լ�)
	double x = pow(fabs(A.centerPosition.x - B.centerPosition.x), 2.0);
	double y = pow(fabs(A.centerPosition.y - B.centerPosition.y), 2.0);

	// �� �� ������ �Ÿ�
	double d = sqrt(x + y);

	// �� ���� ������ ��
	double r = ((A.radius / 2) + (B.radius / 2));

	// �Ÿ��� �������� �պ��� ũ�ٸ� FALSE
	if (d > r)
	{
		return FALSE;
	}

	return TRUE;
}

/// <summary>
/// ���� �ڽ��� �浹
/// </summary>
/// <param name="A">�ڽ� (�»�, ���� ���� ������ �ִ� ����ü)</param>
/// <param name="B">�� (������ ������ ������ �ִ� ����ü)</param>
/// <returns>��ġ�� true</returns>
bool CollisionCheck_BtoC(Bullet A, RECT B)
{
	Vector2D Left_Top = { B.left, B.top };
	Vector2D Left_Bottom = {B.left, B.bottom};
	Vector2D Right_Top = {B.right, B.top};
	Vector2D Right_Bottom = { B.right, B.bottom };

	int r = A.radius / 2;

	RECT expendRECT1 = { B.left - r, B.top,
		B.right + r, B.bottom };
	RECT expendRECT2 = { B.left, B.top - r,
		B.right, B.bottom + r };

	// ������ ��ŭ Ȯ��� �ڽ� �ȿ� ���� ������ �ִٸ�?
	if (CollisionCheck_RtoP(expendRECT1, A.centerPosition) == TRUE)
	{
		return TRUE;
	}

	if (CollisionCheck_RtoP(expendRECT2, A.centerPosition) == TRUE)
	{
		return TRUE;
	}

	// �ڽ��� �𼭸��� �� �ȿ� �ִٸ�?
	if (CollisionCheck_CtoP(A, Left_Top) == TRUE)
	{
		return TRUE;
	}
	if (CollisionCheck_CtoP(A, Left_Bottom) == TRUE)
	{
		return TRUE;
	}
	if (CollisionCheck_CtoP(A, Right_Top) == TRUE)
	{
		return TRUE;
	}
	if (CollisionCheck_CtoP(A, Right_Bottom) == TRUE)
	{
		return TRUE;
	}

	return FALSE;
}