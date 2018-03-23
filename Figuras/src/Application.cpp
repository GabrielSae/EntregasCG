#include "stdafx.h"
#include "Application.h"
#define PI 3.141592



Application::Application()
{
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

void Application::setup()
{
	while (ent < 3 || ent >360) {
		std::cout << "Ingresa lados" << std::endl;
		std::cin >> ent;
	}
}

void Application::ClearScreen()
{
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			putPixel(i, j, 0, 0, 0, 0);
		}
	}
}

//void Application::Update()
//{
//}

void Application::draw()
{
	posX = 512;
	posY = 512;
	if (ent >= 3 && ent <= 360) {
		ClearScreen();
		float angulo = 360 / ent;
		for (float i = 0; i <= 360; i += angulo) {
			double x2 = 300 * cos(i*3.1416 / 180);
			double y2 = 300 * sin(i*3.1416 / 180);
			putPixel(x2+512, y2+512, 255, 255, 255, 0);
			LineTo(x2+512, y2+512);
		}
	}
}