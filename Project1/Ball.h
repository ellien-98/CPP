#pragma once
#include "config.h"
#include "gameobject.h"
#include "graphics.h"
#include <string>
#include <iostream>
#include "util.h"


class Ball : public Gameobject, public Collidable {

	float pos_x, pos_y;
	float speed;
	float size = 25;
	float rotation;
	float level;
	graphics::Brush brush;
	bool active = true;

	std::string planetpath;
	float originalX = CANVAS_WIDTH / 2, originalY = CANVAS_HEIGHT / 2;
	eDir direction;

public:
	void update() override;
	void draw() override;
	void init() override;
	bool isActive() { return active; }
	void Reset();
	void randomDirection();
	float getX() { return pos_x; }
	float getY() { return pos_y; }
	eDir getDirection() { return direction; }
	void changeDirection(eDir d);
	void moveBall();
	Ball(const Game& mygame, float gameLevel);
	std::string getPlanet() { return planetpath; }   //functions to get and set 
	//void setPlanet(std::string pl) { planetpath = pl; } //the planet path according to users insertion
	void setLevel(float l) { level = l; }
	float getLevel() {
		return level;
	}

	~Ball();
	Disk getCollisionHull() const override;

};




