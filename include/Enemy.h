#pragma once
#include "cinder/gl/gl.h"
#include "Character.h"
#include "InputHandler.h"
class Enemy : public Character
{
public:
	Enemy();
	float health;
	void attack();
};