#include "stdafx.h"
#include "Application.h"
#include "Vec3.h"
#include "SierpinskyGasket.h"
#include "Mat3.h"
#include "Mat4.h"
#include "Vec4.h"
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
	Vec4 V0 = Vec4(-100, -100, 100),V1 = Vec4(-100, 100, 100),V2 = Vec4(100, 100, 100),V3 = Vec4(100, -100, 100),
		V4 = Vec4(100, 100, -100),V5 = Vec4(100, -100, -100),V6 = Vec4(-100, 100, -100),V7 = Vec4(-100, -100, -100);
	//cara a, triangulo I:
	V.push_back(V0);V.push_back(V1);V.push_back(V2);
	//cara a, triangulo S
	V.push_back(V0);V.push_back(V2);V.push_back(V3);
	//cara b, triangulo I
	V.push_back(V3);V.push_back(V2);V.push_back(V4);
	//cara b, triangulo S
	V.push_back(V3);V.push_back(V4);V.push_back(V5);
	//cara c, triangulo I
	V.push_back(V5);V.push_back(V4);V.push_back(V6);
	//cara c, triangulo S
	V.push_back(V5);V.push_back(V6);V.push_back(V7);
	//cara d, triangulo I
	V.push_back(V7);V.push_back(V6);V.push_back(V1);
	//cara d, triangulo S
	V.push_back(V7);V.push_back(V1);V.push_back(V0);
	//cara e, triangulo I
	V.push_back(V7);V.push_back(V0);V.push_back(V3);
	//cara e, triangulo S
	V.push_back(V7);V.push_back(V3);V.push_back(V5);
	//cara f, triangulo I
	V.push_back(V1);V.push_back(V6);V.push_back(V4);
	//cara f, triangulo S
	V.push_back(V1);V.push_back(V4);V.push_back(V2);

	eye.m[0] = WIDTH/2;	eye.m[1] = HEIGHT/2;	eye.m[2] = 200;	eye.m[3] = 1;

	target.m[0] = 0;	target.m[1] = 0;	target.m[2] = 0;	target.m[3] = 1;

	up.m[0] = 0;	up.m[1] = 1;	up.m[2] = 0;	up.m[3] = 1;
}

void Application::update()
{
	setColor(coloractual, 0, 0, 0, 0);
	++angulo;
	Mat4 Identidad;
	
	Mat4 RotarenX;
	Mat4 RotarenY;
	Mat4 RotarenZ;
	RotarenX = Mat4::RotateX(angulo);
	RotarenY = Mat4::RotateY(angulo);
	RotarenZ = Mat4::RotateZ(angulo);

	//Todo esto va en setup
	Vec4 EscalaCabeza(0.5, 0.5, 0.5); Vec4 EscalaCuerpo(1, 1.5, 1); Vec4 EscalaBrazos(0.3, 0.9, 0.3); Vec4 EscalaAnteBrazos(0.3, 0.5, 0.3);
	Vec4 EscalaManos(0.3, 0.3, 0.3); Vec4 EscalaPiernas(0.4, 0.9, 0.4); Vec4 EscalaPantorrillas(0.4, 0.7, 0.4); Vec4 EscalaPies(0.4, 0.3, 0.7);

	Vec4 TrasladarCabeza(0, -360, 0); Vec4 TrasladarBrazoI(150, -200, 0); Vec4 TrasladarBrazoR(-150, -200, 0); Vec4 TrasladarAnteBrazoI(150, -55, 0);
	Vec4 TrasladarAnteBrazoR(-150, -55, 0); Vec4 TrasladarManoI(150, 30, 0); Vec4 TrasladarManoD(-150, 30, 0); Vec4 TrasladarPI(50, 95, 0);
	Vec4 TrasladarCuerpo(0, -150, 0); Vec4 TrasladarPD(-50, 95, 0); Vec4 TrasladarPantI(50, 265, 0); Vec4 TrasladarPantD(-50, 265, 0);
	Vec4 TrasladarPieI(50, 370, 30); Vec4 TrasladarPieD(-50, 370, 30);

	Mat4 EscCabeza = Mat4::Scale(EscalaCabeza); Mat4 EscCuerpo = Mat4::Scale(EscalaCuerpo); Mat4 EscBrazos = Mat4::Scale(EscalaBrazos);
	Mat4 EscAnteBrazos = Mat4::Scale(EscalaAnteBrazos); Mat4 EscPiernas = Mat4::Scale(EscalaPiernas); Mat4 EscPantorrillas = Mat4::Scale(EscalaPantorrillas);
	Mat4 EscPies = Mat4::Scale(EscalaPies); Mat4 EscManos = Mat4::Scale(EscalaManos);

	Mat4 TraslCabeza = Mat4::Translate(TrasladarCabeza); Mat4 TraslBrazoI = Mat4::Translate(TrasladarBrazoI); Mat4 TraslBrazoR = Mat4::Translate(TrasladarBrazoR);
	Mat4 TraslAnteI = Mat4::Translate(TrasladarAnteBrazoI); Mat4 TraslAnteR = Mat4::Translate(TrasladarAnteBrazoR); Mat4 TraslMI = Mat4::Translate(TrasladarManoI);
	Mat4 TraslMD = Mat4::Translate(TrasladarManoD); Mat4 TrasPI = Mat4::Translate(TrasladarPI); Mat4 TraslCuerpo = Mat4::Translate(TrasladarCuerpo);
	Mat4 TraslPD = Mat4::Translate(TrasladarPD); Mat4 TraslPantI = Mat4::Translate(TrasladarPantI); Mat4 TraslPantD = Mat4::Translate(TrasladarPantD);
	Mat4 TraslPieI = Mat4::Translate(TrasladarPieI); Mat4 TraslPieD = Mat4::Translate(TrasladarPieD);

	Mat4 Mirar = Mat4::LookAt(eye, target, up);
	Mat4 Proyeccion = Mat4::Orthogonal(HEIGHT/2, -HEIGHT/2, WIDTH/2, -WIDTH/2, -500, 500);
	Mat4 MIRPROY = Proyeccion * Mirar;

	Mat4 AcumCabeza = TraslCabeza*RotarenY*EscCabeza;
	Mat4 AcumBrazoI = (RotarenY*TraslBrazoI*EscBrazos);
	Mat4 AcumBrazoR = (RotarenY*TraslBrazoR*EscBrazos);
	Mat4 AcumCuerpo = (RotarenY*TraslCuerpo*EscCuerpo);
	Mat4 AcumAnteI = (RotarenY*TraslAnteI*EscAnteBrazos);
	Mat4 AcumAnteR = (RotarenY*TraslAnteR*EscAnteBrazos);
	Mat4 AcumMI = (RotarenY*TraslMI*EscManos);
	Mat4 AcumMD = (RotarenY*TraslMD*EscManos);
	Mat4 AcumPI = (RotarenY*TrasPI*EscPiernas);
	Mat4 AcumPD = (RotarenY*TraslPD*EscPiernas);
	Mat4 AcumPantI = RotarenY * TraslPantI*EscPantorrillas;
	Mat4 AcumPantD = RotarenY * TraslPantD*EscPantorrillas;
	Mat4 AcumPieI = (RotarenY*TraslPieI*EscPies);
	Mat4 AcumPieD = (RotarenY*TraslPieD*EscPies);
	////La convencion de el orden de matrices en CG es la siguiente (pregunta de examen)
	//De derecha a izquierda
	Vcopy2.clear();//borra el cubo
	Head.clear();
	Body.clear();
	Rarm.clear();
	Larm.clear();
	LForearm.clear();
	RForearm.clear();
	LHand.clear();
	RHand.clear();
	LLeg.clear();
	RLeg.clear();
	LCalf.clear();
	RCalf.clear();
	RFoot.clear();
	LFoot.clear();
	for (int i = 0; i < V.size(); ++i) {
		Vcopy2.push_back(Vec4(V[i]));
		Head.push_back(Vec4(AcumCabeza*V[i]));
		Body.push_back(Vec4(AcumCuerpo*V[i]));
		Rarm.push_back(Vec4(AcumBrazoR*V[i]));
		Larm.push_back(Vec4(AcumBrazoI*V[i]));
		LForearm.push_back(Vec4(AcumAnteI*V[i]));
		RForearm.push_back(Vec4(AcumAnteR*V[i]));
		LHand.push_back(Vec4(AcumMI*V[i]));
		RHand.push_back(Vec4(AcumMD*V[i]));
		LLeg.push_back(Vec4(AcumPI*V[i]));
		RLeg.push_back(Vec4(AcumPD*V[i]));
		LCalf.push_back(Vec4(AcumPantI*V[i]));
		RCalf.push_back(Vec4(AcumPantD*V[i]));
		LFoot.push_back(Vec4(AcumPieI*V[i]));
		RFoot.push_back(Vec4(AcumPieD*V[i]));
	}
}

void Application::draw()
{
	ClearScreen(coloractual);
	drawGeometry(Head, TRIANGLES);
	drawGeometry(Body, TRIANGLES);
	drawGeometry(Rarm, TRIANGLES);
	drawGeometry(Larm, TRIANGLES);
	drawGeometry(LForearm, TRIANGLES);
	drawGeometry(RForearm, TRIANGLES);
	drawGeometry(LHand, TRIANGLES);
	drawGeometry(RHand, TRIANGLES);
	drawGeometry(LLeg, TRIANGLES);
	drawGeometry(RLeg, TRIANGLES);
	drawGeometry(LCalf, TRIANGLES);
	drawGeometry(RCalf, TRIANGLES);
	drawGeometry(LFoot, TRIANGLES);
	drawGeometry(RFoot, TRIANGLES);
}