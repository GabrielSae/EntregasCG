#include "stdafx.h"
#include "Application.h"
#include "Vec3.h"
#include "SierpinskyGasket.h"
#include "Mat3.h"
#include "Mat4.h"
#include "Vec4.h"
#define PI 3.141592

SierpinskyGasket SG;

void Application::MidPointCircle(int Cx, int Cy, int R) {
	int x = 0;
	int y = R;
	int d = 1 - R;
	while (x<y) {
		putPixel(x + Cx, y + Cy,255,255,255,255);
		putPixel(x + Cx, -y + Cy, 255, 255, 255, 255);
		putPixel(-x + Cx, y + Cy, 255, 255, 255, 255);
		putPixel(-x + Cx, -y + Cy, 255, 255, 255, 255);
		putPixel(y + Cx, x + Cy, 255, 255, 255, 255);
		putPixel(-y + Cx, x + Cy, 255, 255, 255, 255);
		putPixel(-y + Cx, -x + Cy, 255, 255, 255, 255);
		putPixel(y + Cx, -x + Cy, 255, 255, 255, 255);
		if (d<0) {
			d += 2 * x;
		}
		else {
			--y;
			d += 2 * x - 2 * y;
		}
		++x;
	}
}

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
	for (int i = 1; i < 3; i++) {
		LineTo(VT[i].m[0], VT[i].m[1]);
	}
	for (int i = 3; i < VT.size(); i++) {
		LineTo(VT[i - 1].m[0], VT[i - 1].m[1]);
		LineTo(VT[i - 2].m[0], VT[i - 2].m[1]);
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
void Application::drawTriangleFan(const std::vector<Vec4>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	moveTo(VT[0].m[0], VT[0].m[1]);
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
void Application::drawLines(const std::vector<Vec4>& VT) {
	if (VT.size() <= 0) {
		return;
	}
	moveTo(VT[0].m[0], VT[0].m[1]);
	for (int i = 0; i < VT.size() - 1; i += 2) {
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
			putPixel1(i, j, coloractual);
		}
	}
}

void Application::setup()
{
	X1 = rand() % WIDTH / 2;		Y1 = rand() % HEIGHT / 2;		R1 = rand() % 100 + 1;
	X2 = rand() % WIDTH / 2;		Y2 = rand() % HEIGHT / 2;		R2 = rand() % 100 + 1;
	X3 = rand() % WIDTH / 2;		Y3 = rand() % HEIGHT / 2;		R3 = rand() % 100 + 1;
	X4 = rand() % WIDTH / 2;		Y4 = rand() % HEIGHT / 2;		R4 = rand() % 100 + 1;
	X5 = rand() % WIDTH / 2;		Y5 = rand() % HEIGHT / 2;		R5 = rand() % 100 + 1;
	X6 = rand() % WIDTH / 2;		Y6 = rand() % HEIGHT / 2;		R6 = rand() % 100 + 1;
	X7 = rand() % WIDTH / 2;		Y7 = rand() % HEIGHT / 2;		R7 = rand() % 100 + 1;
	X8 = rand() % WIDTH / 2;		Y8 = rand() % HEIGHT / 2;		R8 = rand() % 100 + 1;
	X9 = rand() % WIDTH / 2;		Y9 = rand() % HEIGHT / 2;		R9 = rand() % 100 + 1;
	X10 = rand() % WIDTH / 2;		Y10 = rand() % HEIGHT / 2;		R10 = rand() % 100 + 1;
	X11 = rand() % WIDTH / 2;		Y11 = rand() % HEIGHT / 2;		R11 = rand() % 100 + 1;
	X12 = rand() % WIDTH / 2;		Y12 = rand() % HEIGHT / 2;		R12 = rand() % 100 + 1;
	X13 = rand() % WIDTH / 2;		Y13 = rand() % HEIGHT / 2;		R13 = rand() % 100 + 1;
	X14 = rand() % WIDTH / 2;		Y14 = rand() % HEIGHT / 2;		R14 = rand() % 100 + 1;
	X15 = rand() % WIDTH / 2;		Y15 = rand() % HEIGHT / 2;		R15 = rand() % 100 + 1;
}	

void Application::update()
{
	setColor(coloractual, 0, 0, 0, 0);
	++angulo;
	Mat4 RotarenX = Mat4::RotateX(angulo);
	Mat4 RotarenY = Mat4::RotateY(angulo);
	Mat4 RotarenZ = Mat4::RotateZ(angulo);
	Vec4 EscalaCabeza(0.5, 0.5, 0.5);
	Vec4 EscalaCuerpo(1, 1.5, 1);
	Vec4 EscalaBrazos(0.3, 0.9, 1);
	Vec4 EscalaAnteBrazos(0.3, 0.5, 1);
	Vec4 EscalaManos(0.3, 0.3, 1);
	Vec4 EscalaPiernas(0.5, 0.9, 1);
	Vec4 EscalaPantorrillas(0.5, 0.5, 1);
	Vec4 EscalaPies(0.5, 0.3, 1);
	Vec4 TrasladarCabeza(0, -420, 0);
	Vec4 TrasladarBrazoI(0, -50, 200);
	Vec4 TrasladarBrazoR(0, -50, -200);
	Mat4 EscCabeza = Mat4::Scale(EscalaCabeza);
	Mat4 EscCuerpo = Mat4::Scale(EscalaCuerpo);
	Mat4 EscBrazos = Mat4::Scale(EscalaBrazos);
	Mat4 EscAnteBrazos = Mat4::Scale(EscalaAnteBrazos);
	Mat4 EscPiernas = Mat4::Scale(EscalaPiernas);
	Mat4 EscPantorrillas = Mat4::Scale(EscalaPantorrillas);
	Mat4 EscPies = Mat4::Scale(EscalaPies);
	Mat4 EscManos = Mat4::Scale(EscalaManos);
	Mat4 TraslCabeza = Mat4::Translate(TrasladarCabeza);
	Mat4 TraslBrazoI = Mat4::Translate(TrasladarBrazoI);
	Mat4 TraslBrazoR = Mat4::Translate(TrasladarBrazoR);
	Mat4 AcumCabeza = TraslCabeza;
	Mat4 AcumBrazoI = (EscBrazos * TraslBrazoI);
	Mat4 AcumBrazoR = (EscBrazos * TraslBrazoR);
	Mat4 AcumCuerpo = (EscCuerpo*RotarenY);
	Mat4 Mirar = Mat4::LookAt(eye, target, up);
	Mat4 proyeccion = Mat4::Orthogonal(HEIGHT/2, -HEIGHT/2, WIDTH/2, -WIDTH/2, -500, 500);
	////La convencion de el orden de matrices en CG es la siguiente (pregunta de examen)
	//De derecha a izquierda
	Vcopy2.clear();//borra el cubo
	Head.clear();
	Body.clear();
	Rarm.clear();
	Larm.clear();
	RForearm.clear();
	LForearm.clear();
	RHand.clear();
	LHand.clear();
	RLeg.clear();
	LLeg.clear();
	RCalf.clear();
	LCalf.clear();
	RFoot.clear();
	LFoot.clear();
	for (int i = 0; i < V.size(); ++i) {
		Vcopy2.push_back(Vec4(V[i]));
		Head.push_back(Vec4(AcumCabeza*V[i]));
		Body.push_back(Vec4(AcumCuerpo*V[i]));
		Rarm.push_back(Vec4(AcumBrazoR*V[i]));
		Larm.push_back(Vec4(AcumBrazoI*V[i]));
		LForearm.push_back(Vec4(EscAnteBrazos*V[i]));
		RForearm.push_back(Vec4(EscAnteBrazos*V[i]));
		RHand.push_back(Vec4(EscManos*V[i]));
		LHand.push_back(Vec4(EscManos*V[i]));
		RLeg.push_back(Vec4(EscPiernas*V[i]));
		LLeg.push_back(Vec4(EscPiernas*V[i]));
		RCalf.push_back(Vec4(EscPantorrillas*V[i]));
		LCalf.push_back(Vec4(EscPantorrillas*V[i]));
		RFoot.push_back(Vec4(EscPies*V[i]));
		LFoot.push_back(Vec4(EscPies*V[i]));
	}
	//Vcopy.push_back(Vec3(Identidad * SG.vertices[0]));
}

void Application::draw()
{
	//ClearScreen(coloractual);
	MidPointCircle(X1, Y1, R1);
	MidPointCircle(X2, Y2, R2);
	MidPointCircle(X3, Y3, R3);
	MidPointCircle(X4, Y4, R4);
	MidPointCircle(-X5, Y5, R5);
	MidPointCircle(-X6, Y6, R6);
	MidPointCircle(-X7, Y7, R7);
	MidPointCircle(-X8, Y8, R8);
	MidPointCircle(-X9, -Y9, R9);
	MidPointCircle(-X10, -Y10, R10);
	MidPointCircle(-X11, -Y11, R11);
	MidPointCircle(-X12, -Y12, R12);
	MidPointCircle(X13, -Y13, R13);
	MidPointCircle(X14, -Y14, R14);
	MidPointCircle(X15, -Y15, R15);
}