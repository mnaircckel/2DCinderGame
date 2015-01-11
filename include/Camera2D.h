#pragma once
#include "cinder/gl/gl.h"
#include "InputHandler.h"

using namespace ci;

class Camera2D
{
public:
	Camera2D();
	Vec2f location;
	Vec2f velocity;
	Vec2f targetLocation;
	Vec2f targetRemaining;
	float speed;
	bool isPanning;
	bool isFollowing;

	void panTo(float newSpeed, Vec2f goToLocation);
	void getInput(InputHandler input);
	void update();
};