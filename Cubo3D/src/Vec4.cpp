#include "Vec4.h"
#include <math.h>

Vec4::Vec4()
{
	m[0] = 0;
	m[1] = 0;
	m[2] = 0;
	m[3] = 1;
}

Vec4::Vec4(const float& x, const float& y, const float& z) {
	m[0] = x;
	m[1] = y;
	m[2] = z;
	m[3] = 1;
}

Vec4::Vec4(const Vec4& vec) { //copia
	for (int i = 0; i < 4; i++) {
			m[i] = vec.m[i];
	}
}

void Vec4::normalize() {
	float magnitud = sqrt((m[0] * m[0]) + (m[1] * m[1]) + (m[2] * m[2]));
	m[0] = m[0] / magnitud;
	m[1] = m[1] / magnitud;
	m[2] = m[2] / magnitud;
	m[3] = 1;
}

Vec4& Vec4::cross(const Vec4& rh) {
	Vec4 result;
	result.m[0] = (m[1] * rh.m[2]) - (m[2] * rh.m[1]);
	result.m[1] = -1 * ((m[0] * rh.m[2]) - (m[2] * rh.m[0]));
	result.m[2] = (m[0] + rh.m[1]) - (m[1] * rh.m[0]);
	result.m[3] = 1;
	return result;
}

float& Vec4::dot(const Vec4& rh) {
	float result;
	result = (m[0] * rh.m[0]) + (m[1] * rh.m[1]) + (m[2] * rh.m[2]);
	return result;
}

Vec4::~Vec4()
{
}
