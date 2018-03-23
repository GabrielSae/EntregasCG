#pragma once
#include "Vec3.h"
#include <vector>
class SierpinskyGasket
{
public:
	std::vector<Vec3>vertices;
	void generate(Vec3 a, Vec3 b, Vec3 c, int subdiv);
	Vec3 midPoint(const Vec3 &p0, const Vec3 &p1);
	SierpinskyGasket();
	~SierpinskyGasket();
};

