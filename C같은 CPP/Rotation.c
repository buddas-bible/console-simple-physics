#define _USE_MATH_DEFINES
#include <math.h>

#include "Rotation.h"


/// <summary>
/// �簢���� ������ ã�� �Լ�
/// </summary>
/// <param name="rect">�˻���� ��ǥ�� ������ �簢��</param>
/// <returns>���� ��ǥ</returns>
Vector2D Rotation_FindCenter(RECT rect)
{
	int x = (rect.right - rect.left) / 2.0;
	int y = (rect.bottom - rect.top) / 2.0;
	Vector2D center = { x, y };

	return center;
}

/*
Vector2D Rotation_FindLeftTop(Player player)
{
	int x = player.centerPosition.x - player.radius;
	int y = player.centerPosition.y - player.radius;
	Vector2D point = { x, y };
	return point;
}

Vector2D Rotation_FindRightTop(Player player)
{
	int x = player.centerPosition.x + player.radius;
	int y = player.centerPosition.y - player.radius;
	Vector2D point = { x, y };
	return point;
}

Vector2D Rotation_FindLeftBottom(Player player)
{
	int x = player.centerPosition.x - player.radius;
	int y = player.centerPosition.y + player.radius;
	Vector2D point = { x, y };
	return point;
}

Vector2D Rotation_FindRightBottom(Player player)
{
	int x = player.centerPosition.x + player.radius;
	int y = player.centerPosition.y + player.radius;
	Vector2D point = { x, y };
	return point;
}
*/

/// <summary>
/// rarian theta��ŭ ȸ���ϴ� �Լ�
/// </summary>
/// <param name="p">x,y��ǥ�� ������ ����ü</param>
/// <param name="theta">radian</param>
/// <returns>��ȯ��</returns>
Vector2D Rotation_VectorRotation(Vector2D vector, double theta)
{
	// [ cos -sin]  [x]
	// [ sin cos ]  [y]
	// cos��Ÿ x - sin��Ÿ y, sin��Ÿ x + cos��Ÿ y
	double tempX = vector.x;
	double tempY = vector.y;

	vector.x = (cos(theta) * tempX) - (sin(theta) * tempY);
	vector.y = (sin(theta) * tempX) + (cos(theta) * tempY);

	return vector;
}

/// <summary>
/// ������ �������� �簢���� ȸ���ϴ� �Լ�
/// </summary>
/// <param name="rect">�»���� ��ǥ�� ������ �簢��</param>
/// <param name="theta">radian ����</param>
void Rotation_PlayerRotation(Player* player, double theta)
{
	// ���� ���͸� ��ȯ��
	player->heightVector = Rotation_VectorRotation(player->heightVector, theta);
	player->widthVector = Rotation_VectorRotation(player->widthVector, theta);
	
	//���Ϳ��� �� ���� ���͸� ���Ѵ�.
	Vector2D OtoLT = Vector2D_Sub(player->plgVertex[0], player->centerPosition);
	Vector2D OtoRT = Vector2D_Sub(player->plgVertex[1], player->centerPosition);
	Vector2D OtoLB = Vector2D_Sub(player->plgVertex[2], player->centerPosition);
	Vector2D OtoRB = Vector2D_Sub(player->plgVertex[3], player->centerPosition);

	// ����->�� ���͸� ȸ����Ų��.
	OtoLT = Rotation_VectorRotation(OtoLT, theta);
	OtoRT = Rotation_VectorRotation(OtoRT, theta);
	OtoLB = Rotation_VectorRotation(OtoLB, theta);
	OtoRB = Rotation_VectorRotation(OtoRB, theta);

	// ȸ����Ų ���Ϳ� ���͸� ���Ѵ�.
	player->plgVertex[0] = Vector2D_Add(OtoLT, player->centerPosition);
	player->plgVertex[1] = Vector2D_Add(OtoRT, player->centerPosition);
	player->plgVertex[2] = Vector2D_Add(OtoLB, player->centerPosition);
	player->plgVertex[3] = Vector2D_Add(OtoRB, player->centerPosition);
}

/// <summary>
/// �÷��̾� ĳ���Ͱ� ���콺�� �ٶ󺸰� �ϴ� �Լ�
/// </summary>
/// <param name="player">�÷��̾� ����ü</param>
/// <param name="Mouse">���콺 ��ǥ�� ���� ����ü</param>
void Rotation_LookAtMouse(Player* player, Vector2D Mouse)
{
	// ĳ����->���콺 ���͸� ���Ѵ�.
	// ���͸� ����ȭ ���Ѽ� ������ �����ϰ� �Ѵ�.
	Vector2D playertoMouse = Vector2D_Normalization(Vector2D_Sub(Mouse, player->centerPosition));
	Vector2D playerHead = Vector2D_Add(player->centerPosition, player->heightVector);
	
	// �÷��̾�->���콺 ���Ϳ� ��� ���Ϳ��� ������ ����
	double theta = Vector2D_FindTheta(playertoMouse, player->heightVector);

	//theta = floor(theta * 10000000000000) / 10000000000000;

	// �ð����� �ݽð����� ������ ���⼺�� ����.
	double ccw = CollisionCheck_CCW(playerHead, Mouse, player->centerPosition);
	
	// �ݽð�
	if (ccw > 0)
	{
		Rotation_PlayerRotation(player, theta);
	}
	// �ð�
	else if (ccw < 0)
	{
		Rotation_PlayerRotation(player, theta * -1.0);
	}
	else
	{
		return;
	}
}