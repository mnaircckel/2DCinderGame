#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Camera2D.h"
#include "Character.h"
#include "InputHandler.h"
#include "Player.h"
#include "Item.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class GameApp : public AppNative {
  public:
	void prepareSettings(Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void update();
	void draw();

	bool isPaused;

	Player player;
	Camera2D camera;
	InputHandler input;

};


void GameApp::prepareSettings(Settings *settings)
{
	settings->setFrameRate(60.0f);
	settings->setWindowSize(800, 600);
}

void GameApp::setup()
{
	isPaused = false;
	camera.isFollowing = true;

}

void GameApp::mouseDown( MouseEvent event )
{
	camera.panTo(15.0f, Vec2f(getMousePos().x-getWindowPos().x, getMousePos().y-getWindowPos().y));
}

void GameApp::keyDown(KeyEvent event)
{

	if (event.getChar() == 'p'){
		isPaused = !isPaused;
	}

	if (event.getCode() == KeyEvent::KEY_RIGHT){
		input.rightDown = true;
		input.lastLeftRight = "Right";
	}
	else if (event.getCode() == KeyEvent::KEY_LEFT){
		input.leftDown = true;
		input.lastLeftRight = "Left";
	}
	else if (event.getCode() == KeyEvent::KEY_UP){
		input.upDown = true;
		input.lastUpDown = "Up";
	}
	else if (event.getCode() == KeyEvent::KEY_DOWN){
		input.downDown = true;
		input.lastUpDown = "Down";
	}

	if (event.getChar() == 'a'){
		input.aDown = true;
		input.lastAD = "a";
	}
	else if (event.getChar() == 'd'){
		input.dDown = true;
		input.lastAD = "d";
	}
	else if (event.getChar() == 'w'){
		input.wDown = true;
		input.lastWS = "w";
	}
	else if (event.getChar() == 's'){
		input.sDown = true;
		input.lastWS = "s";
	}
	camera.getInput(input);
	player.getInput(input);
}

void GameApp::keyUp(KeyEvent event)
{
	if (event.getCode() == KeyEvent::KEY_RIGHT){
		input.rightDown = false;
	}
	else if (event.getCode() == KeyEvent::KEY_LEFT){
		input.leftDown = false;
	}
	else if (event.getCode() == KeyEvent::KEY_UP){
		input.upDown = false;
	}
	else if (event.getCode() == KeyEvent::KEY_DOWN){
		input.downDown = false;
	}

	if (event.getChar() == 'a'){
		input.aDown = false;
	}
	else if (event.getChar() == 'd'){
		input.dDown = false;
	}
	else if (event.getChar() == 'w'){
		input.wDown = false;
	}
	else if (event.getChar() == 's'){
		input.sDown = false;
	}
	camera.getInput(input);
	player.getInput(input);

}

void GameApp::update()
{
	if (!isPaused){
		camera.update();
		player.update();
		if (camera.isFollowing)
			camera.location -= player.velocity;
	}
}

void GameApp::draw()
{
	gl::clear();
	player.draw(camera);
	gl::drawSolidCircle(Vec2f(camera.location.x+150,camera.location.y+60), 15.0f);
	gl::drawSolidCircle(Vec2f(camera.location.x+123, camera.location.y-20), 15.0f);
	gl::drawSolidCircle(Vec2f(camera.location.x+340, camera.location.y+200), 15.0f);
	//player.draw(camera);
}

CINDER_APP_NATIVE( GameApp, RendererGl )
