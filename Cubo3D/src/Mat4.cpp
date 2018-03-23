#include "Mat4.h"
#include <math.h>

Mat4::Mat4()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				m[i][j] = 1;
			}
			else {
				m[i][j] = 0;
			}
		}
	}
}

Mat4::Mat4(const Mat4& mat) { //copia
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = mat.m[i][j];
		}
	}
}

Mat4::Mat4(const float& v) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int j = 0; j < 4; j++) {
				if (i == j) {
					m[i][j] = v;
				}
				else {
					m[i][j] = 0;
				}
			}
		}
	}
}

Mat4 Mat4::Identity() {
	Mat4 mat;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				mat.m[i][j] = 1;
			}
			else {
				mat.m[i][j] = 0;
			}
		}
	}
	return mat;
}

Mat4 Mat4::RotateX(const float& angle) {
	Mat4 mat;
	mat.m[0][0] = 1;
	mat.m[0][1] = 0;
	mat.m[0][2] = 0;
	mat.m[0][3] = 0;
	mat.m[1][0] = 0;
	mat.m[1][1] = cos(angle*3.1416 / 180.0);
	mat.m[1][2] = sin(angle*3.1416 / 180.0)*-1;
	mat.m[1][3] = 0;
	mat.m[2][0] = 0;
	mat.m[2][1] = sin(angle*3.1416 / 180.0);
	mat.m[2][2] = cos(angle*3.1416 / 180.0);
	mat.m[2][3] = 0;
	mat.m[3][0] = 0;
	mat.m[3][1] = 0;
	mat.m[3][2] = 0;
	mat.m[3][3] = 1;
	return mat;
}

Mat4 Mat4::RotateY(const float& angle) {
	Mat4 mat;
	mat.m[0][0] = cos(angle*3.1416 / 180.0);
	mat.m[0][1] = 0;
	mat.m[0][2] = sin(angle*3.1416 / 180.0);
	mat.m[0][3] = 0;
	mat.m[1][0] = 0;
	mat.m[1][1] = 1;
	mat.m[1][2] = 0;
	mat.m[1][3] = 0;
	mat.m[2][0] = sin(angle*3.1416 / 180.0) * -1;
	mat.m[2][1] = 0;
	mat.m[2][2] = cos(angle*3.1416 / 180.0);
	mat.m[2][3] = 0;
	mat.m[3][0] = 0;
	mat.m[3][1] = 0;
	mat.m[3][2] = 0;
	mat.m[3][3] = 1;
	return mat;
}

Mat4 Mat4::RotateZ(const float& angle) {
	Mat4 mat;
	mat.m[0][0] = cos(angle*3.1416 / 180.0);
	mat.m[0][1] = sin(angle*3.1416 / 180.0) * -1;
	mat.m[0][2] = 0;
	mat.m[0][3] = 0;
	mat.m[1][0] = sin(angle*3.1416 / 180.0);
	mat.m[1][1] = cos(angle*3.1416 / 180.0);
	mat.m[1][2] = 0;
	mat.m[1][3] = 0;
	mat.m[2][0] = 0;
	mat.m[2][1] = 0;
	mat.m[2][2] = 1;
	mat.m[2][3] = 0;
	mat.m[3][0] = 0;
	mat.m[3][1] = 0;
	mat.m[3][2] = 0;
	mat.m[3][3] = 1;
	return mat;
}

Mat4 Mat4::operator*(const Mat4& rh) const
{
	Mat4 result;
	result.m[0][0] = (m[0][0] * rh.m[0][0]) + (m[0][1] * rh.m[1][0]) + (m[0][2] * rh.m[2][0]) + (m[0][3] * rh.m[3][0]);
	result.m[0][1] = (m[0][0] * rh.m[0][1]) + (m[0][1] * rh.m[1][1]) + (m[0][2] * rh.m[2][1]) + (m[0][3] * rh.m[3][1]);
	result.m[0][2] = (m[0][0] * rh.m[0][2]) + (m[0][1] * rh.m[1][2]) + (m[0][2] * rh.m[2][2]) + (m[0][3] * rh.m[3][2]);
	result.m[0][3] = (m[0][0] * rh.m[0][3]) + (m[0][1] * rh.m[1][3]) + (m[0][2] * rh.m[2][3]) + (m[0][3] * rh.m[3][3]);

	result.m[1][0] = (m[1][0] * rh.m[0][0]) + (m[1][1] * rh.m[1][0]) + (m[1][2] * rh.m[2][0]) + (m[1][3] * rh.m[3][0]);
	result.m[1][1] = (m[1][0] * rh.m[0][1]) + (m[1][1] * rh.m[1][1]) + (m[1][2] * rh.m[2][1]) + (m[1][3] * rh.m[3][1]);
	result.m[1][2] = (m[1][0] * rh.m[0][2]) + (m[1][1] * rh.m[1][2]) + (m[1][2] * rh.m[2][2]) + (m[1][3] * rh.m[3][2]);
	result.m[1][3] = (m[1][0] * rh.m[0][3]) + (m[1][1] * rh.m[1][3]) + (m[1][2] * rh.m[2][3]) + (m[1][3] * rh.m[3][3]);

	result.m[2][0] = (m[2][0] * rh.m[0][0]) + (m[2][1] * rh.m[1][0]) + (m[2][2] * rh.m[2][0]) + (m[2][3] * rh.m[3][0]);
	result.m[2][1] = (m[2][0] * rh.m[0][1]) + (m[2][1] * rh.m[1][1]) + (m[2][2] * rh.m[2][1]) + (m[2][3] * rh.m[3][1]);
	result.m[2][2] = (m[2][0] * rh.m[0][2]) + (m[2][1] * rh.m[1][2]) + (m[2][2] * rh.m[2][2]) + (m[2][3] * rh.m[3][2]);
	result.m[2][3] = (m[2][0] * rh.m[0][3]) + (m[2][1] * rh.m[1][3]) + (m[2][2] * rh.m[2][3]) + (m[2][3] * rh.m[3][3]);

	result.m[3][0] = (m[3][0] * rh.m[0][0]) + (m[3][1] * rh.m[1][0]) + (m[3][2] * rh.m[2][0]) + (m[3][3] * rh.m[3][0]);
	result.m[3][1] = (m[3][0] * rh.m[0][1]) + (m[3][1] * rh.m[1][1]) + (m[3][2] * rh.m[2][1]) + (m[3][3] * rh.m[3][1]);
	result.m[3][2] = (m[3][0] * rh.m[0][2]) + (m[3][1] * rh.m[1][2]) + (m[3][2] * rh.m[2][2]) + (m[3][3] * rh.m[3][2]);
	result.m[3][3] = (m[3][0] * rh.m[0][3]) + (m[3][1] * rh.m[1][3]) + (m[3][2] * rh.m[2][3]) + (m[3][3] * rh.m[3][3]);
	return result;
}

Mat4& Mat4::operator=(const Mat4& rh)
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			this->m[i][j] = rh.m[i][j];
		}
	}
	return *this;
}

Mat4 Mat4::Translate(const Vec4& v) {
	Mat4 mat;
	mat.m[0][0] = 1;
	mat.m[0][1] = 0;
	mat.m[0][2] = 0;
	mat.m[0][3] = v.m[0];
	mat.m[1][0] = 0;
	mat.m[1][1] = 1;
	mat.m[1][2] = 0;
	mat.m[1][3] = v.m[1];
	mat.m[2][0] = 0;
	mat.m[2][1] = 0;
	mat.m[2][2] = 1;
	mat.m[2][3] = v.m[2];
	mat.m[3][0] = 0;
	mat.m[3][1] = 0;
	mat.m[3][2] = 0;
	mat.m[3][3] = 1;
	return mat;
}

Mat4 Mat4::Scale(const Vec4& v) {
	Mat4 mat;
	mat.m[0][0] = v.m[0];
	mat.m[0][1] = 0;
	mat.m[0][2] = 0;
	mat.m[0][3] = 0;
	mat.m[1][0] = 0;
	mat.m[1][1] = v.m[1];
	mat.m[1][2] = 0;
	mat.m[1][3] = 0;
	mat.m[2][0] = 0;
	mat.m[2][1] = 0;
	mat.m[2][2] = v.m[2];
	mat.m[2][3] = 0;
	mat.m[3][0] = 0;
	mat.m[3][1] = 0;
	mat.m[3][2] = 0;
	mat.m[3][3] = 1;
	return mat;
}

Vec4 Mat4::operator*(const Vec4& rh) const
{
	Vec4 result;
	result.m[0] = (m[0][0] * rh.m[0]) + (m[0][1] * rh.m[1]) + (m[0][2] * rh.m[2]) + (m[0][3] * rh.m[3]);
	result.m[1] = (m[1][0] * rh.m[0]) + (m[1][1] * rh.m[1]) + (m[1][2] * rh.m[2]) + (m[1][3] * rh.m[3]);
	result.m[2] = (m[2][0] * rh.m[0]) + (m[2][1] * rh.m[1]) + (m[2][2] * rh.m[2]) + (m[2][3] * rh.m[3]);
	result.m[3] = (m[3][0] * rh.m[0]) + (m[3][1] * rh.m[1]) + (m[3][2] * rh.m[2]) + (m[3][3] * rh.m[3]);
	return result;
}

Mat4 Mat4::LookAt(const Vec4& eye, const Vec4& target, const Vec4& up) {
	Vec4 tarmenoseye;

	//para esto tuviste que hacer el operador resta entre vectores
	for (int i = 0; i < 3; ++i) {
		tarmenoseye.m[i] = eye.m[i] - target.m[i];
	}
	tarmenoseye.m[3] = 1;
	tarmenoseye.normalize();
	Vec4 z = tarmenoseye;
	Vec4 x1 = z.cross(up);
	x1.normalize();
	Vec4 x = x1;
	Vec4 y1 = x.cross(z);
	y1.normalize();
	Vec4 y = y1;
	Mat4 ejes;
	ejes.m[0][3] = ejes.m[1][3] = ejes.m[2][3] = ejes.m[3][0] = ejes.m[3][1] = ejes.m[3][2] = 0;
	ejes.m[3][3] = 1;
	ejes.m[0][0] = x.m[0];
	ejes.m[0][1] = x.m[1];
	ejes.m[0][2] = x.m[2];
	ejes.m[1][0] = y.m[0];
	ejes.m[1][1] = y.m[1];
	ejes.m[1][2] = y.m[2];
	ejes.m[2][0] = z.m[0];
	ejes.m[2][1] = z.m[1];
	ejes.m[2][2] = z.m[2];
	Mat4 ojonegativo;
	ojonegativo.m[0][1] = ojonegativo.m[0][2] = ojonegativo.m[1][0] = ojonegativo.m[1][2] = ojonegativo.m[2][0] =
		ojonegativo.m[2][1] = ojonegativo.m[3][0] = ojonegativo.m[3][1] = ojonegativo.m[3][2] = 0;
	ojonegativo.m[0][0] = ojonegativo.m[1][1] = ojonegativo.m[2][2] = ojonegativo.m[3][3] = 1;
	ojonegativo.m[0][3] = -1 * (eye.m[0]);
	ojonegativo.m[0][3] = -1 * (eye.m[1]);
	ojonegativo.m[0][3] = -1 * (eye.m[2]);
	Mat4 Visual;
	Visual = ejes * ojonegativo;
	return Visual;
}

Mat4 Mat4::Orthogonal(const float R, const float L, const float T, const float B, const float N, const float F) {
	Mat4 Ort;
	Mat4 Esc;
	Esc.m[0][0] = 2 / (R - L);
	Esc.m[1][1] = 2 / (T - B);
	Esc.m[2][2] = 2 / (N - F);
	Esc.m[3][3] = 1;
	Esc.m[0][1] = Esc.m[0][2] = Esc.m[0][3] = Esc.m[1][0] = Esc.m[1][2] = Esc.m[1][3] =
		Esc.m[2][0] = Esc.m[2][1] = Esc.m[2][3] = Esc.m[3][0] = Esc.m[3][1] = Esc.m[3][2] = 0;
	Mat4 Tras;
	Tras.m[0][0] = Tras.m[1][1] = Tras.m[2][2] = Tras.m[3][3] = 1;
	Tras.m[0][1] = Tras.m[0][2] = Tras.m[1][0] = Tras.m[1][2] = Tras.m[2][0] =
		Tras.m[2][1] = Tras.m[3][0] = Tras.m[3][1] = Tras.m[3][2] = 0;
	Tras.m[0][3] = -1 * ((R + L) / 2);
	Tras.m[1][3] = -1 * ((T + B) / 2);
	Tras.m[2][3] = ((N + F) / 2);
	Ort = Esc * Tras;
	return Ort;
}

Mat4::~Mat4()
{
}