#include "Enemy.h"
#include "cinder/gl/texture.h"
#include "cinder/ImageIo.h"
#include "cinder/app/AppNative.h"


Enemy::Enemy()
{
	sprite = loadImage(app::loadAsset("pyro.png"));
	location = Vec2f(100, 100);
	velocity = Vec2f(0, 0);
	acceleration = Vec2f(0, 0);
	health = 100.0;
}
