#pragma once
#include "gameobject.h"
#include "config.h"
#include "util.h"
//#include "game.h"	//


class Paddle : public Gameobject, public Collidable {

	float speed = 2.0f;
	float pos_x, pos_y;
	//float originalX=CANVAS_WIDTH-250, originalY = CANVAS_HEIGHT/2;
	float height = 1.0f;

public:
	Paddle(const class Game& mygame);
	//Paddle* player1 = nullptr;
	//Paddle* player2 = nullptr;
	void update() override;
	void draw() override;
	void init() override;
	float getPosY() { return pos_y; }
	float getPosX() { return pos_x; }
	void setPosY(float posy) { pos_y = posy; }
	void setPosX(float posx) { pos_x = posx; }
	void resetY(Paddle* player);
	void upwards();
	void downwards();
	Disk getCollisionHull() const override;

};

