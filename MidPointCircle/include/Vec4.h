#pragma once
class Vec4
{
public:
	float m[4];
	Vec4(); //(0,0,0,1)
	Vec4(const float& x, const float& y, const float& z);
	Vec4(const Vec4& v); //copia
	void normalize();
	Vec4& cross(const Vec4& v);
	float& dot(const Vec4& v);
	~Vec4();
};
