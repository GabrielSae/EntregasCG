#pragma once
#include "Mat3.h"
class Vec3
{
public:
	double m[3];
	float x();
	float y();
	Vec3(float x, float y);
	Vec3(const Vec3& v);

	~Vec3();

	Vec3& operator= (const Vec3& rh);
};

