#pragma once
#include "BaseApplication.h"
#include "Vec3.h"
#include "Mat3.h"
#include "SierpinskyGasket.h"

class Application : public BaseApplication
{
public:
	Color coloractual;
	void setColor(Color c, const char& r, const char& g, const char& b, const char& a);
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
	void ClearScreen(Color c);
	void drawLineStrip(const std::vector<Vec3>& VT);
	void drawTriangles(const std::vector<Vec3>& VT);
	void drawTriangleFan(const std::vector<Vec3>& VT);
	void drawLines(const std::vector<Vec3>& VT);
	void drawLineLoop(const std::vector<Vec3>& VT);
	void drawTriangleStrip(const std::vector<Vec3>& VT);
	void drawPoints(const std::vector<Vec3>& VT);
	float angulo = 0.0f;
	float escala = 1.0f;
	void setup() override;
	void update() override;
	void draw() override;
	~Application();
	std::vector<Vec3> Vcopy;
};
