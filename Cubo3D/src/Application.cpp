#include "stdafx.h"
#include "Application.h"
#include "Vec3.h"
#include "SierpinskyGasket.h"
#include "Mat3.h"
#include "Mat4.h"
#include "Vec4.h"
#define PI 3.141592

SierpinskyGasket SG;

void Application::setColor(Color c, const int& r, const int& g, const int& b, const int& a) {
	c.m[0] = r;
	c.m[1] = g;
	c.m[2] = b;
	c.m[3] = a;
	c.R(r);
	c.G(g);
	c.B(b);
	c.A(a);
}

Application::Application()
{
}

void Application::drawGeometry(const std::vector<Vec3>& VT, Tipo tipo) {
	switch (tipo)
	{
	case Application::TRIANGLES:
		drawTriangles(VT);
		break;
	case Application::POINTS:
		drawPoints(VT);
		break;
	case Application::LINES:
		drawLines(VT);
		break;
	case Application::LINESTRIP:
		drawLineStrip(VT);
		break;
	case Application::LINELOOP:
		drawLineLoop(VT);
		break;
	case Application::TRIANGLESTRIP:
		drawTriangleStrip(VT);
		break;
	case Application::TRIANGLEFAN:
		drawTriangleFan(VT);
		break;
	default:
		drawTriangles(VT);
		break;
	}
}
void Application::drawGeometry(const std::vector<Vec4>& VT, Tipo tipo) {
	switch (tipo)
	{
	case Application::TRIANGLES:
		drawTriangles(VT);
		break;
	case Application::POINTS:
		drawPoints(VT);
		break;
	case Application::LINES:
		drawLines(VT);
		break;
	case Application::LINESTRIP:
		drawLineStrip(VT);
		break;
	case Application::LINELOOP:
		drawLineLoop(VT);
		break;
	case Application::TRIANGLESTRIP:
		drawTriangleStrip(VT);
		break;
	case Application::TRIANGLEFAN:
		drawTriangleFan(VT);
		break;
	default:
		drawTriangles(VT);
		break;
	}
}

void Application::drawPoints(const std::vector<Vec3>& VT) {
	for (int i = 0; i < VT.size(); ++i) {
		putPixel(VT[i].m[0], VT[i].m[1], 250, 30, 25, 255);
	}
}
void Application::drawPoints(const std::vector<Vec4>& VT) {
	for (int i = 0; i < VT.size(); ++i) {
		putPixel(VT[i].m[0], VT[i].m[1], 250, 30, 25, 255);
	}
}

void Application::drawTriangleStrip(const std::vector<Vec3>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	moveTo(VT[0].m[0], VT[0].m[1]);
	for (int i = 1; i < 3; i++) {
		LineTo(VT[i].m[0], VT[i].m[1]);
	}
	for (int i = 3; i < VT.size(); i++) {
		LineTo(VT[i-1].m[0], VT[i-1].m[1]);
		LineTo(VT[i-2].m[0], VT[i-2].m[1]);
	}
}
void Application::drawTriangleStrip(const std::vector<Vec4>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	moveTo(VT[0].m[0], VT[0].m[1]);
	int limit = VT.size() - (VT.size() % 3);
	for (int i = 1; i < 3; i++) {
		LineTo(VT[i].m[0], VT[i].m[1]);
	}
	LineTo(VT[0].m[0], VT[0].m[1]);
	for (int i = 3; i < limit; i++) {
		LineTo(VT[i-1].m[0], VT[i-1].m[1]);
		LineTo(VT[i-2].m[0], VT[i-2].m[1]);
	}
}

void Application::drawLineLoop(const std::vector<Vec3>& VT) {
	drawLineStrip(VT);
	if (VT.size() <= 0) {
		return;
	}
	LineTo(VT[0].m[0], VT[0].m[1]);
}
void Application::drawLineLoop(const std::vector<Vec4>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	drawLineStrip(VT);
	LineTo(VT[0].m[0], VT[0].m[1]);
}

void Application::drawTriangleFan(const std::vector<Vec3>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	moveTo(VT[0].m[0],VT[0].m[1]);
	for (int i = 1; i < VT.size(); i++) {
		LineTo(VT[i].m[0], VT[i].m[1]);
		LineTo(VT[0].m[0], VT[0].m[1]);
	}
}
void Application::drawTriangleFan(const std::vector<Vec4>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	moveTo(VT[0].m[0], VT[0].m[1]);
	for (int i = 1; i < 3; i++) {
		LineTo(VT[i].m[0], VT[i].m[1]);
	}
	LineTo(VT[0].m[0], VT[0].m[1]);
	for (int i = 3; i < VT.size(); ++i) {
		moveTo(VT[i].m[0], VT[i].m[1]);
		LineTo(VT[i - 1].m[0], VT[i - 1].m[1]);
		moveTo(VT[i].m[0], VT[i].m[1]);
		LineTo(VT[0].m[0], VT[0].m[1]);
	}
	moveTo(VT[VT.size()-1].m[0], VT[VT.size() - 1].m[1]);
	LineTo(VT[1].m[0], VT[1].m[1]);
}

void Application::drawLines(const std::vector<Vec3>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	moveTo(VT[0].m[0], VT[0].m[1]);
	for (int i = 0; i < VT.size()-1; i += 2) {
		LineTo(VT[i+1].m[0], VT[i+1].m[1]);
	}
}
void Application::drawLines(const std::vector<Vec4>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	for (int i = 0; i < VT.size()-1; i +=2) {
		moveTo(VT[i].m[0], VT[i].m[1]);
		LineTo(VT[i + 1].m[0], VT[i + 1].m[1]);
	}
}

void Application::drawLineStrip(const std::vector<Vec3>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	moveTo(VT[0].m[0],VT[0].m[1]);
	for (int i = 1; i < VT.size(); i++) {
		LineTo(VT[i].m[0], VT[i].m[1]);
	}
}
void Application::drawLineStrip(const std::vector<Vec4>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	moveTo(VT[0].m[0], VT[0].m[1]);
	for (int i = 0; i < VT.size(); i++) {
		LineTo(VT[i].m[0], VT[i].m[1]);
	}
}

void Application::drawTriangles(const std::vector<Vec3>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	size_t limit = VT.size() - (VT.size() % 3);
	for (size_t i = 0; i < limit; i += 3) {
		moveTo(VT[i].m[0], VT[i].m[1]);
		LineTo(VT[i + 1].m[0], VT[i + 1].m[1]);
		LineTo(VT[i + 2].m[0], VT[i + 2].m[1]);
		LineTo(VT[i].m[0], VT[i].m[1]);
	}
}
void Application::drawTriangles(const std::vector<Vec4>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	size_t limit = VT.size() - (VT.size() % 3);
	for (size_t i = 0; i < limit; i += 3) {
		moveTo(VT[i].m[0], VT[i].m[1]);
		LineTo(VT[i + 1].m[0], VT[i + 1].m[1]);
		LineTo(VT[i + 2].m[0], VT[i + 2].m[1]);
		LineTo(VT[i].m[0], VT[i].m[1]);
	}
}

void Application::moveTo(float x, float y) {
	posX = x;
	posY = y;
}

void Application::LineTo(float x, float y) {
	drawLine(posX, posY, x, y);
	moveTo(x, y);
}

Application::~Application()
{
}

void Application::ClearScreen(Color c)
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			putPixel(i-WIDTH/2, j-HEIGHT/2, c.R(), c.G(), c.B(), c.A());
		}
	}
}

void Application::setup()
{
	setColor(coloractual, '0', '0', '0', '0');

	Vec4 V0 = Vec4(-100, 100, 100), V1 = Vec4(-100, -100, 100), V2 = Vec4(100, -100, 100), V3 = Vec4(100, 100, 100),
		V4 = Vec4(100, -100, -100), V5 = Vec4(100, 100, -100), V6 = Vec4(-100, -100, -100), V7 = Vec4(-100, 100, -100);
	//cara a, triangulo I
	V.push_back(V0); V.push_back(V1); V.push_back(V2);
	//cara a, triangulo S
	V.push_back(V0); V.push_back(V2); V.push_back(V3);
	//cara b, triangulo I
	V.push_back(V3); V.push_back(V2); V.push_back(V4);
	//cara b, triangulo S
	V.push_back(V3); V.push_back(V4); V.push_back(V5);
	//cara c, triangulo I
	V.push_back(V5); V.push_back(V4); V.push_back(V6);
	//cara c, triangulo S
	V.push_back(V5); V.push_back(V6); V.push_back(V7);
	//cara d, triangulo I
	V.push_back(V7); V.push_back(V6); V.push_back(V1);
	//cara d, triangulo S
	V.push_back(V7); V.push_back(V1); V.push_back(V0);
	//cara e, triangulo I
	V.push_back(V7); V.push_back(V0); V.push_back(V3);
	//cara e, triangulo S
	V.push_back(V7); V.push_back(V3); V.push_back(V5);
	//cara f, triangulo I
	V.push_back(V1); V.push_back(V6); V.push_back(V4);
	//cara f, triangulo S
	V.push_back(V1); V.push_back(V4); V.push_back(V2);

	eye.m[0] = 100; eye.m[1] = 10; eye.m[2] = -1; eye.m[3] = 1;

	target.m[0] = 0; target.m[1] = 0; target.m[2] = 0; target.m[3] = 1;

	up.m[0] = 0; up.m[1] = 1; up.m[2] = 0; up.m[3] = 1;

	////ParteExtra
	Vec4 E1(250, 250, 0), E2(280, 250, 0), E3(250, 280, 0), E4(280, 280, 0), E5(250, 310, 0), E6(280, 310, 0);
	Vcopy3.push_back(E1); Vcopy3.push_back(E2); Vcopy3.push_back(E3); Vcopy3.push_back(E4); Vcopy3.push_back(E5); Vcopy3.push_back(E6);
	Vec4 F1(0, 0, 0), F2(20, 0, 0), F3(0, 20, 0), F4(20, 20, 0), F5(0, 40, 0), F6(20, 40, 0);
	Vcopy4.push_back(F1); Vcopy4.push_back(F2); Vcopy4.push_back(F3); Vcopy4.push_back(F4); Vcopy4.push_back(F5); Vcopy4.push_back(F6);
	Vec4 G1(40, 0, 0), G2(60, 0, 0), G3(40, 20, 0), G4(60, 20, 0), G5(40, 40, 0), G6(60, 40, 0);
	Vcopy5.push_back(G1); Vcopy5.push_back(G2); Vcopy5.push_back(G3); Vcopy5.push_back(G4); Vcopy5.push_back(G5); Vcopy5.push_back(G6);
	Vec4 H1(80, 0, 0), H2(100, 0, 0), H3(80, 20, 0), H4(100, 20, 0), H5(80, 40, 0), H6(100, 40, 0);
	Vcopy6.push_back(H1); Vcopy6.push_back(H2); Vcopy6.push_back(H3); Vcopy6.push_back(H4); Vcopy6.push_back(H5); Vcopy6.push_back(H6);
	Vec4 I1(0, -200, 0), I2(50, -300, 0), I3(100, -200, 0), I4(150, -300, 0), I5(200, -200, 0), I6(250, -300, 0);
	Vcopy7.push_back(I1); Vcopy7.push_back(I2); Vcopy7.push_back(I3); Vcopy7.push_back(I4); Vcopy7.push_back(I5); Vcopy7.push_back(I6);
	Vec4 J1(-200, -100, 0), J2(-100, -100, 0), J3(-100, 0, 0), J4(-200, 0, 0), J5(-300, 0, 0), J6(-300, -100, 0), J7(-300, -200, 0), J8(-200, -200, 0), J9(-100, -200, 0);
	Vcopy8.push_back(J1); Vcopy8.push_back(J2); Vcopy8.push_back(J3); Vcopy8.push_back(J4); Vcopy8.push_back(J5); Vcopy8.push_back(J6); Vcopy8.push_back(J7);
	Vcopy8.push_back(J8); Vcopy8.push_back(J9);
}

void Application::update()
{
	++angulo;
	angulo1 += 5;
	angulo2 += 10;
	escala -= 0.01f;
	if (escala <= 0.5f) {
		escala = 1.0f;
	}
	if (angulo >= 360) {
		angulo = 0;
	}
	Mat4 RotarenX = Mat4::RotateX(angulo1);
	Mat4 RotarenY = Mat4::RotateY(angulo);
	Mat4 RotarenZ = Mat4::RotateZ(angulo2);
	Vec4 Tras(300, 0, 0);
	Vec4 Tras2(-300, 0, 0);
	Vec4 Escala(0.5, 0.5, 0.5);
	Mat4 Trasladar = Mat4::Translate(Tras);
	Mat4 Trasladar2 = Mat4::Translate(Tras2);
	Mat4 Escalar = Mat4::Scale(Escala);
	Mat4 Identidad = Mat4::Identity();
	Mat4 Mirar = Mat4::LookAt(eye, target, up);
	Mat4 proyeccion = Mat4::Orthogonal(HEIGHT/2, -HEIGHT/2, WIDTH/2, -WIDTH/2, -500, 500);
	////La convencion de el orden de matrices en CG es la siguiente (pregunta de examen)
	//De derecha a izquierda
	Mat4 Acum0 = Mirar * proyeccion;
	Mat4 Acum = RotarenX * RotarenY;
	Mat4 Acum2 = RotarenZ * Trasladar;
	Mat4 Acumulado1 = Acum2 * Acum;
	Mat4 Acumulado2 = Acum0 * Acumulado1;
	Vcopy2.clear();//borra el cubo
	for (int i = 0; i < V.size(); ++i) {
		Vcopy2.push_back(Vec4(Acumulado1 * V[i]));
	}
	//Vcopy.push_back(Vec3(Identidad * SG.vertices[0]));
}

void Application::draw()
{
	ClearScreen(coloractual);
	//drawGeometry(SG.vertices, TRIANGLES);
	//putPixel(angulo, angulo, 255, 255, 255, 255);
	drawGeometry(Vcopy2, TRIANGLES);
	/*drawGeometry(Vcopy3, POINTS);
	drawGeometry(Vcopy4, LINES);
	drawGeometry(Vcopy5, LINESTRIP);
	drawGeometry(Vcopy6, LINELOOP);
	drawGeometry(Vcopy7, TRIANGLESTRIP);
	drawGeometry(Vcopy8, TRIANGLEFAN);*/
}
