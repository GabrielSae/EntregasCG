#pragma once
#include "BaseApplication.h"
#include "Vec3.h"
#include "Mat3.h"
#include "SierpinskyGasket.h"
#include "Vec4.h"

class Application : public BaseApplication
{
public:
	Color coloractual;
	void setColor(Color c, const int& r, const int& g, const int& b, const int& a);
	float posX;
	float posY;
	enum Tipo {
		TRIANGLES,
		POINTS,
		LINES,
		LINESTRIP,
		LINELOOP,
		TRIANGLESTRIP,
		TRIANGLEFAN
	};
	float ent = 0;
	void moveTo(float x, float y);
	void LineTo(float x, float y);
	Application();
	void drawGeometry(const std::vector<Vec3>& VT, Tipo tipo);
	void drawGeometry(const std::vector<Vec4>& VT, Tipo tipo);
	void drawLineStrip(const std::vector<Vec3>& VT);
	void drawLineStrip(const std::vector<Vec4>& VT);
	void drawTriangles(const std::vector<Vec3>& VT);
	void drawTriangles(const std::vector<Vec4>& VT);
	void drawTriangleFan(const std::vector<Vec3>& VT);
	void drawTriangleFan(const std::vector<Vec4>& VT);
	void drawLines(const std::vector<Vec3>& VT);
	void drawLines(const std::vector<Vec4>& VT);
	void drawLineLoop(const std::vector<Vec3>& VT);
	void drawLineLoop(const std::vector<Vec4>& VT);
	void drawTriangleStrip(const std::vector<Vec3>& VT);
	void drawTriangleStrip(const std::vector<Vec4>& VT);
	void drawPoints(const std::vector<Vec3>& VT);
	void drawPoints(const std::vector<Vec4>& VT);
	void ClearScreen(Color c);
	float angulo = 0.0f;
	float angulo1 = 0.0f;
	float angulo2 = 0.0f;
	float escala = 1.0f;
	void setup() override;
	void update() override;
	void draw() override;
	~Application();
	std::vector<Vec3> Vcopy;
	std::vector<Vec4> Vcopy2;
	std::vector<Vec4> V;
	std::vector<Vec4> Vcopy3;
	std::vector<Vec4> Vcopy4;
	std::vector<Vec4> Vcopy5;
	std::vector<Vec4> Vcopy6;
	std::vector<Vec4> Vcopy7;
	std::vector<Vec4> Vcopy8;
	Vec4 eye;
	Vec4 target;
	Vec4 up;
	Vec4 tarmenoseye;
};
