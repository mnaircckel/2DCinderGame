#include "Player.h"
#include "cinder/gl/texture.h"
#include "cinder/ImageIo.h"
#include "cinder/app/AppNative.h"


Player::Player()
{
	Character();
	sprite = loadImage(app::loadAsset("doctor.png"));
	location = Vec2f(400, 300);
	velocity = Vec2f(0, 0);
	acceleration = Vec2f(0, 0);
	health = 100.0;

}

void Player::getInput(InputHandler input)
{
	if (input.aDown && input.dDown){
		if (input.lastAD == "d")
			velocity.x = 5;
		else if (input.lastAD == "a")
			velocity.x = -5;
	}
	else if (input.dDown)
		velocity.x = 5;
	else if (input.aDown)
		velocity.x = -5;
	else
		velocity.x = 0;

	if (input.wDown && input.sDown){
		if (input.lastWS == "w")
			velocity.y = -5;
		else if (input.lastWS == "s")
			velocity.y = 5;
	}
	else if (input.wDown)
		velocity.y = -5;
	else if (input.sDown)
		velocity.y = 5;
	else
		velocity.y = 0;

	if ((input.dDown || input.aDown) && (input.wDown || input.sDown)){
		velocity /= sqrt(5*5 * 2);
		velocity *= 5;
	}

}