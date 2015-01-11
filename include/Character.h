#pragma once
#include "Camera2D.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace std;

class Character
{
public:
	Vec2f location;
	Vec2f velocity;
	Vec2f acceleration;
	Character::Character();
	Character::Character(Vec2f newLocation, Vec2f newVelocity, Vec2f newAcceleration);
	void update();
	void draw(Camera2D camera);
};