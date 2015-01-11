#pragma once

#include <string>

using namespace std;

class InputHandler{
public:
	InputHandler();

	bool rightDown;
	bool leftDown;
	string lastLeftRight;
	

	bool upDown;
	bool downDown;
	string lastUpDown;

	bool aDown;
	bool dDown;
	string lastAD;


	bool wDown;
	bool sDown;
	string lastWS;

};