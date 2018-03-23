#pragma once
#include "Vec3.h"
class Mat3
{
public:
	double m[3][3];
	Mat3();
	Mat3(const float& value);

	static Mat3& Translate(const float& Tx, const float& Ty);
	static Mat3& Rotate(float angle);
	static Mat3& Escalate(const float& Ex, const float& Ey);

	Vec3& operator* (const Vec3& rh) const;
	Mat3& operator* (const Mat3& rh) const;

	~Mat3();
};

