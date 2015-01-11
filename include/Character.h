#pragma once
#include "cinder/gl/gl.h"
#include "Camera2D.h"
using namespace ci;
using namespace std;

class Character
{
public:
	Character();
	Character(Vec2f newLocation, Vec2f newVelocity, Vec2f newAcceleration);

	Vec2f location;
	Vec2f velocity;
	Vec2f acceleration;
	
	void update();
	void draw(Camera2D camera);
};