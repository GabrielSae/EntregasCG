#include "Application.h"



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
	for (int i = 256; i < 769; i++) {
		putPixel(i, 512, 255, 0, 0, 255);
		putPixel(512, i, 0, 255, 0, 255);
		putPixel(i, i, 0, 0, 255, 255);
		putPixel(i, HEIGHT-i, 255, 255, 255, 255);

		putPixel(i, 256, 255, 255, 0, 255);
		putPixel(i, 768, 255, 255, 0, 255);
		putPixel(256, i, 255, 255, 0, 255);
		putPixel(768, i, 255, 255, 0, 255);
	}
}
