#include "cinder/gl/gl.h"
#include "Character.h"


Character::Character(){

}

Character::Character(Vec2f newLocation, Vec2f newVelocity, Vec2f newAcceleration){
	location = newLocation;
	velocity = newVelocity;
	acceleration = newAcceleration;
}


void Character::update(){
	velocity += acceleration;
	location += velocity;
}


void Character::draw(){
	gl::drawSolidCircle(location,15.0f);
}