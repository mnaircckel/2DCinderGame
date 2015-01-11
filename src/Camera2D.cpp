#include "cinder/gl/gl.h"
#include "Camera2D.h"

Camera2D::Camera2D(){
	isPanning = false;
	isFollowing = false;
	location = Vec2f(0, 0);
	velocity = Vec2f(0, 0);
	targetRemaining = Vec2f(0, 0);
	targetLocation = Vec2f(0, 0);
	speed = 5.0f;
}

void Camera2D::update()
{
	if (isPanning){
		location -= velocity;
		targetRemaining -= Vec2f(abs(velocity.x),abs(velocity.y));
		if (targetRemaining.x <= 0 && targetRemaining.y <= 0){
			isPanning = false;
			location = targetLocation;
			velocity = Vec2f(0, 0);
		}
	}
	else if (!isFollowing){
		location += velocity;
	}

}

void Camera2D::panTo(float newSpeed, Vec2f goToTarget)
{
	if (location == goToTarget)
		return;
	isPanning = true;
	targetLocation = goToTarget;
	float deltaX = location.x - goToTarget.x;
	float deltaY = location.y - goToTarget.y;
	velocity = Vec2f(deltaX, deltaY);
	velocity /= sqrt(deltaX*deltaX + deltaY*deltaY);
	velocity *= newSpeed;
	targetRemaining = Vec2f(abs(deltaX),abs(deltaY));
}

void Camera2D::getInput(InputHandler input)
{
	if (isPanning || isFollowing){
		return;
	}

	if (input.leftDown && input.rightDown){
		if (input.lastLeftRight == "Right")
			velocity.x = -speed;
		else if (input.lastLeftRight == "Left")
			velocity.x = speed;
	}
	else if (input.rightDown)
		velocity.x = -speed;
	else if (input.leftDown)
		velocity.x = speed;
	else
		velocity.x = 0;

	if (input.upDown && input.downDown){
			if (input.lastUpDown == "Up")
				velocity.y = speed;
			else if (input.lastUpDown == "Down")
				velocity.y = -speed;
	}
	else if (input.upDown)
		velocity.y = speed;
	else if (input.downDown)
		velocity.y = -speed;
	else
		velocity.y = 0;

	if ((input.rightDown || input.leftDown) && (input.upDown || input.downDown)){
		velocity /= sqrt(speed*speed*2);
		velocity *= speed;
	}

}