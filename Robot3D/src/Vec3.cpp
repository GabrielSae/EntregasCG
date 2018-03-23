#include "stdafx.h"
#include "Vec3.h"


Vec3::Vec3(float x, float y)
{
	m[0] = x;
	m[1] = y;
	m[2] = 1;
}

float Vec3::x() {
	return m[0];
}



float Vec3::y() {
	return m[1];
}

Vec3::Vec3(const Vec3& v) {
	m[0] = v.m[0];
	m[1] = v.m[1];
	m[2] = v.m[2];
}

Vec3::~Vec3()
{
}

Vec3& Vec3::operator= (const Vec3& rh)
{
	m[0] = rh.m[0];
	m[1] = rh.m[1];
	m[2] = rh.m[2];

	return *this;
}