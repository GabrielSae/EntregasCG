#include "stdafx.h"
#include "Application.h"
#include "Vec3.h"
#include "SierpinskyGasket.h"
#include "Mat3.h"
#define PI 3.141592

SierpinskyGasket SG;

void Application::setColor(Color c, const char& r, const char& g, const char& b, const char& a) {
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

void Application::drawPoints(const std::vector<Vec3>& VT) {
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

void Application::drawLineLoop(const std::vector<Vec3>& VT) {
	drawLineStrip(VT);
	if (VT.size() <= 0) {
		return;
	}
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

void Application::drawLines(const std::vector<Vec3>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	moveTo(VT[0].m[0], VT[0].m[1]);
	for (int i = 0; i < VT.size()-1; i += 2) {
		LineTo(VT[i+1].m[0], VT[i+1].m[1]);
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
			putPixel1(i, j, coloractual);
		}
	}
}

void Application::setup()
{
	Vec3 a(0, -100), b(100, 100), c(-100, 100);
	SG.generate(a, b, c, 1);
}

void Application::update()
{
	setColor(coloractual, 0, 255, 0, 0);
	++angulo;
	escala -= 0.01f;
	if (escala <= 0.5f) {
		escala = 1.0f;
	}
	if (angulo >= 360) {
		angulo = 0;
	}
	Mat3 Trasladar = Mat3::Translate(300, 0); //WTF
	Mat3 Trasladar2 = Mat3::Translate(0, 0);
	Mat3 Escalar = Mat3::Escalate(escala, escala);
	Mat3 Rotar = Mat3::Rotate(angulo);
	Mat3 Rotar2 = Mat3::Rotate(angulo/5);
	////La convencion de el orden de matrices en CG es la siguiente (pregunta de examen)
	//De derecha a izquierda
	Mat3 Identidad = Mat3();
	Mat3 Acum = Rotar2 * Trasladar;
	Mat3 Acum2 = Rotar;
	Mat3 Acumulado = Acum2 * Acum;
	Vcopy.clear();//borra el triangulo
	for (int i = 0; i < SG.vertices.size(); ++i) {
		Vcopy.push_back(Vec3(Acumulado * SG.vertices[i]));
	}
	//Vcopy.push_back(Vec3(Identidad * SG.vertices[0]));
}

void Application::draw()
{
	ClearScreen(coloractual);
	//drawGeometry(SG.vertices, TRIANGLES);
	//putPixel(angulo, angulo, 255, 255, 255, 255);
	drawGeometry(Vcopy, TRIANGLES);
}