#pragma once


typedef struct Vector3D
{
	double x;
	double y;
	double z;
}Vector3D;

double Vector3D_Size(Vector3D);

Vector3D Vector3D_Add(Vector3D, Vector3D);
Vector3D Vector3D_Sub(Vector3D, Vector3D);

double Vector3D_Dot(Vector3D, Vector3D);
Vector3D Vector3D_Cross(Vector3D, Vector3D);

double Vector3D_FindTheta(Vector3D, Vector3D);
Vector3D Vector3D_Normalization(Vector3D);

double Vector3D_BiggerThen(Vector3D, Vector3D);
double Vector3D_Equality(Vector3D, Vector3D);