#pragma once
#include "cinder/gl/gl.h"
#include "Character.h"
#include "InputHandler.h"
class Player : public Character
{
public:
	float health;
	//vector<Item> inventory;
	void getInput(InputHandler input);
};