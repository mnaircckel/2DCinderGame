#pragma once
#include "Camera2D.h"
#include "cinder/gl/gl.h"

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
	
	Camera2D shitter;
	void update();
	void draw();
};