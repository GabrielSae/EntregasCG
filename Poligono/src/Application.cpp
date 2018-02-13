#include "stdafx.h"
#include "Application.h"
#define PI 3.141592



Application::Application()
{
}


Application::~Application()
{
}

void Application::setup()
{
}

//void Application::update()
//{
//}

void Application::draw()
{
	//for (int i = 0; i < 1024; i++) {
	//	putPixel(i, i, 255, 0, 0, 255); //diagonal derecha
	//	putPixel(512, i, 255, 0, 0, 255); //horizontal
	//	putPixel(i, 512, 255, 0, 0, 255); //vertical
	//	putPixel(HEIGHT-i, i, 255, 0, 0, 255); //diagonal izq
	//}
	////for (int angulo = 180; angulo < 225; angulo++) { //Este ciclo trabaja con angulos
	////	int x = 300 * cos(angulo*PI/180);
	////	int y = 300 * sin(angulo*PI/180);
	////	linea(x+512,y+512,512,512);
	////}
	//for (int angulo = 0; angulo < 45; angulo++) { //Este ciclo trabaja con angulos, al igual que el anterior
	//	int x = 300 * cos(angulo*PI / 180);				//se puede comentar y descomentar el de abajo, es solo para mostrar
	//	int y = 300 * sin(angulo*PI / 180);				//que intenté utilizar ambos metodos
	//	linea(512, 512, x + 512, 512-y);
	//}
	////for (int angulo = 0; angulo < 720; angulo++) { //Este ciclo trabaja con radianes, solo logré medio círculo
	////	int x = 300 * cos(angulo);
	////	int y = 300 * sin(angulo);
	////	linea(512, 512, x + 512, y + 512);
	////}
	//
	//for (int angulo = 0; angulo < 360; angulo++) { //Dibuja la circunferenca a trazar
	//	int x = 300 * cos(angulo*PI / 180);
	//	int y = 300 * sin(angulo*PI / 180);
	//	putPixel(x + 512, y + 512, 0, 255, 200, 255);
	//}
	for (int i = 0; i < 360; ++i) {
		int x = 300 * cos(i*PI / 180);
		int y = 300 * sin(i*PI / 180);
		drawLine(512,512,x+512,y+512);
	}
}

