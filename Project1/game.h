#pragma once
#include "Paddle.h"
#include "Ball.h"


class Game {

	float speed = 2.0f;	//for players
	float gameLevel = 0.4f;
	float posy1 = CANVAS_HEIGHT / 2;		//for player 1
	float posy2 = CANVAS_HEIGHT / 2;		//for player 2
	bool collisionp1 = false, collisionp2 = false;
	typedef enum { STATUS_START, STATUS_PLAYING,STATUS_END } status_t;
	float score1 = 0.0f, score2 = 0.0f;

	Ball* ball = nullptr;
	Paddle* player1 = nullptr;
	Paddle* player2 = nullptr;
	bool player1_initialized = false;
	bool player2_initialized = false;
	bool drawLevelScreen_initialized = false;
	bool debug_mode = false;

	void spawnBall();
	void checkBall();
	bool checkCollision();
	status_t status = STATUS_START;


	unsigned int window_width = WINDOW_WIDTH,
		window_height = WINDOW_HEIGHT;

	void updateStartScreen();
	void updateLevelScreen();
	void updateGameOverScreen();
	void drawGameOverScreen();
	void drawStartScreen();
	void drawLevelScreen();



public:

	void setDebugMode(bool d) { debug_mode = d; }
	bool getDebugMode() const { return debug_mode; }
	void update();
	void draw();
	void init();
	unsigned int getWindowWidth() { return window_width; }
	unsigned int getWindowHeight() { return window_height; }
	float window2canvasX(float x);		//gia metatroph monadwn
	float window2canvasY(float y);
	void setWindowDimension(unsigned int w, unsigned int h) { window_width = w; window_height = h; }		//kanw thn set gia na enhmerwnw to antikeimeno mou (tou game) otan allazoun oi diastaseis tou parathyrou
	void getPoint(Paddle* player);


	Game();
	~Game();

};
