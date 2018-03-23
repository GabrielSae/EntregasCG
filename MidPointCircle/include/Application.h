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
	void MidPointCircle(int Cx, int Cy, int R);
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

	std::vector<Vec4> Head;

	std::vector<Vec4> Body;

	std::vector<Vec4> Larm;

	std::vector<Vec4> Rarm;

	std::vector<Vec4> RForearm;

	std::vector<Vec4> LForearm;

	std::vector<Vec4> RHand;

	std::vector<Vec4> LHand;

	std::vector<Vec4> RLeg;

	std::vector<Vec4> LLeg;

	std::vector<Vec4> RCalf;

	std::vector<Vec4> LCalf;

	std::vector<Vec4> RFoot;

	std::vector<Vec4> LFoot;

	Vec4 eye;
	Vec4 target;
	Vec4 up;
	Vec4 tarmenoseye;

	int X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15,
		Y1, Y2, Y3, Y4, Y5, Y6, Y7, Y8, Y9, Y10, Y11, Y12, Y13, Y14, Y15,
		R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15;
};
