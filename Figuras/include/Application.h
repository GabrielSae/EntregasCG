#pragma once
#include "BaseApplication.h"
class Application : public BaseApplication
{
public:
	float posX;
	float posY;
	float ent = 0;
	void moveTo(float x, float y);
	void LineTo(float x, float y);
	Application();
	~Application();
	void ClearScreen();
	void setup() override;
	//void update() override;
	void draw() override;
};
