#pragma once
#include "Vec4.h"
class Mat4
{
public:
	Mat4();
	float m[4][4];
	Mat4(const Mat4& mat); //copia
	Mat4(const float& v);
	static Mat4 Identity();
	static Mat4 RotateX(const float& angle);
	static Mat4 RotateY(const float& angle);
	static Mat4 RotateZ(const float& angle);
	Mat4 operator*(const Mat4& rh)const;
	Mat4& operator=(const Mat4& rh);

	static Mat4 Translate(const Vec4& v);
	static Mat4 Scale(const Vec4& v);
	Vec4 operator * (const Vec4& v)const;

	static Mat4 LookAt(const Vec4& eye, const Vec4& target, const Vec4& up);
	static Mat4 Orthogonal(const float R, const float L, const float T, const float B, const float N, const float F);
	//Mat4 Perspective(float FOV, float aspectratio, float f, float n);
	~Mat4();
};

