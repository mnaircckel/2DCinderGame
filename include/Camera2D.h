#pragma once
#include "cinder/gl/gl.h"
#include "Character.h"
#include "InputHandler.h"

using namespace ci;

class Camera2D
{
public:
	Vec2f location;
	Vec2f velocity;
	Vec2f targetLocation;
	Vec2f targetRemaining;
	//Character targetCharacter;
	float speed;
	bool isPanning;
	bool isFollowing;

	Camera2D::Camera2D();

	void panTo(float newSpeed, Vec2f goToLocation);
	//void follow(Character goToCharacter);
	void update();
	void getInput(InputHandler input);
};