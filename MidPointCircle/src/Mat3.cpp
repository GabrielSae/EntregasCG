#include "stdafx.h"
#include "Mat3.h"
#include <math.h>

Mat3::Mat3()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				m[i][j] = 1;
			}
			else {
				m[i][j] = 0;
			}
		}
	}
}

Mat3::Mat3(const float& value)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				m[i][j] = value;
			}
			else {
				m[i][j] = 0;
			}
		}
	}

	/*m[0][0] = value;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = value;
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = value;*/
}

Mat3& Mat3::Translate(const float &Tx, const float &Ty)
{
	Mat3 mat;
	/*mat.m[0][0] = 1;
	mat.m[0][1] = 0;
	mat.m[0][2] = Tx;
	mat.m[1][0] = 0;
	mat.m[1][1] = 1;
	mat.m[1][2] = Ty;
	mat.m[2][0] = 0;
	mat.m[2][1] = 0;
	mat.m[2][2] = 1;*/
	mat.m[0][0] = mat.m[1][1] = mat.m[2][2] = 1;
	mat.m[0][2] = Tx; mat.m[1][2] = Ty;
	mat.m[0][1] = mat.m[1][0] = mat.m[2][0] = mat.m[2][1] = 0;
	return mat;
}

Mat3& Mat3::Rotate(float angle)
{
	Mat3 mat;
	mat.m[0][0] = cos(angle*3.1416/180.0);
	mat.m[0][1] = sin(angle*3.1416 / 180.0)*-1;
	mat.m[1][0] = sin(angle*3.1416 / 180.0);
	mat.m[1][1] = cos(angle*3.1416 / 180.0);
	mat.m[2][0] = 0;
	mat.m[2][1] = 0;
	mat.m[0][2] = 1;
	mat.m[1][2] = 1;
	mat.m[2][2] = 1;
	return mat;
}

Mat3& Mat3::Escalate(const float& Ex, const float& Ey) {
	Mat3 mat;
	mat.m[0][0] = Ex;
	mat.m[0][1] = 0;
	mat.m[0][2] = 0;
	mat.m[1][0] = 0;
	mat.m[1][1] = Ey;
	mat.m[1][2] = 0;
	mat.m[2][0] = 0;
	mat.m[2][1] = 0;
	mat.m[2][2] = 1;
	return mat;
}

Vec3& Mat3::operator*(const Vec3& rh) const
{
	Vec3 result(rh.m[0], rh.m[1]);
	/*for (int i = 0; i < 3; ++i) {
		result.m[0] += m[0][i] * rh.m[i];
		result.m[1] += m[1][i] * rh.m[i];
		result.m[2] += m[2][i] * rh.m[i];
	}*/
	result.m[0] = (m[0][0] * rh.m[0]) + (m[0][1] * rh.m[1]) + (m[0][2] * rh.m[2]);
	result.m[1] = (m[1][0] * rh.m[0]) + (m[1][1] * rh.m[1]) + (m[1][2] * rh.m[2]);
	result.m[2] = (m[2][0] * rh.m[0]) + (m[2][1] * rh.m[1]) + (m[2][2] * rh.m[2]);
	return result;

}

Mat3& Mat3::operator*(const Mat3& rh) const
{
	Mat3 result;
	result.m[0][0] = (m[0][0] * rh.m[0][0]) + (m[0][1] * rh.m[1][0]) + (m[0][2] * rh.m[2][0]);
	result.m[0][1] = (m[0][0] * rh.m[0][1]) + (m[0][1] * rh.m[1][1]) + (m[0][2] * rh.m[2][1]);
	result.m[0][2] = (m[0][0] * rh.m[0][2]) + (m[0][1] * rh.m[1][2]) + (m[0][2] * rh.m[2][2]);
	result.m[1][0] = (m[1][0] * rh.m[0][0]) + (m[1][1] * rh.m[1][0]) + (m[1][2] * rh.m[2][0]);
	result.m[1][1] = (m[1][0] * rh.m[0][1]) + (m[1][1] * rh.m[1][1]) + (m[1][2] * rh.m[2][1]);
	result.m[1][2] = (m[1][0] * rh.m[0][2]) + (m[1][1] * rh.m[1][2]) + (m[1][2] * rh.m[2][2]);
	result.m[2][0] = (m[2][0] * rh.m[0][0]) + (m[2][1] * rh.m[1][0]) + (m[2][2] * rh.m[2][0]);
	result.m[2][1] = (m[2][0] * rh.m[0][1]) + (m[2][1] * rh.m[1][1]) + (m[2][2] * rh.m[2][1]);
	result.m[2][2] = (m[2][0] * rh.m[0][2]) + (m[2][1] * rh.m[1][2]) + (m[2][2] * rh.m[2][2]);
	return result;

}

Mat3::~Mat3()
{

}
