#include "game.h"
#include "graphics.h"
#include "config.h"

void Game::spawnBall()
{
	if (!ball) {
		ball = new Ball(*this, this->gameLevel);		//reference sto this(dhladh se ayto to game)
	}

}

void Game::checkBall()
{
	if (ball && !ball->isActive()) {
		delete ball;
		ball = nullptr;		//prepei meta thn katastrofh KAI na to thesw iso me null giati to elegxoun alles synarthseis

	}

}

bool Game::checkCollision()
{
	if (!player1 || !ball || !player2) {
		return false;
	}

	Disk p1 = player1->getCollisionHull();
	Disk p2 = player2->getCollisionHull();
	Disk b = ball->getCollisionHull();

	//left paddle
	if (b.cx + b.radius <= 50 + 60) {
		if (b.cy - b.radius < p1.cy + 30) {
			collisionp1 = true;
			return true;
		}
		if (b.cy + b.radius > p1.cy - 30) {
			collisionp1 = true;
			return true;
		}
	}

	//right paddle
	if (b.cx - b.radius >= 950 - 60) {
		if (b.cy - b.radius < p2.cy + 30) {
			collisionp2 = true;
			return true;
		}
		if (b.cy + b.radius > p2.cy - 30) {
			collisionp2 = true;
			return true;
		}
	}

	return false;

}

void Game::updateStartScreen()
{

	//ENTER BUTTON
	if (graphics::getKeyState(graphics::SCANCODE_RETURN)) {
		status = STATUS_PLAYING;
	}

	//PONTIKI 
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	if (ms.button_left_pressed) {
		status = STATUS_PLAYING;
	}

	//test gia epilogi modes level paixnidiou
	if (graphics::getKeyState(graphics::SCANCODE_H)) {
		this->gameLevel = 1.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_M)) {
		this->gameLevel = 0.4f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_E)) {
		this->gameLevel = 0.2f;
	}

}

void Game::updateLevelScreen()
{
	//create player 1, 2
	if (!player1_initialized && graphics::getGlobalTime() > 1000) {
		player1 = new Paddle(*this);
		player1_initialized = true;
	}
	if (!player2_initialized && graphics::getGlobalTime() > 1000) {
		player2 = new Paddle(*this);
		player2_initialized = true;
	}

	if (player1 && player2) {
		//	LEFT PADDLE
		if (graphics::getKeyState(graphics::SCANCODE_W)) { //player1 up
			player1->upwards();
		}
		if (graphics::getKeyState(graphics::SCANCODE_S)) {	//player1 down
			player1->downwards();
		}
		if (graphics::getKeyState(graphics::SCANCODE_I)) { //player2 up
			player2->upwards();
		}
		if (graphics::getKeyState(graphics::SCANCODE_K)) {	//player2 down
			player2->downwards();
		}
		player1->update();
		player2->update();

		if (score1 > 10 || score2 > 10) //if one of the two players reaches 10 points, game is over 
		{
			status = STATUS_END;
		}

	}


	checkBall();
	spawnBall();

	if (ball) {
		ball->update();
	}

	//	change ball direction when colliding with players
	if (this->checkCollision()) {
		graphics::playSound(std::string(ASSET_PATH) + "hit1.wav", 0.5f, false); //hxos kathe fora pou xtypaei
		if (collisionp1) {
			ball->changeDirection((eDir)((rand() % 3) + 4));
			collisionp1 = false;
			return;
		}
		else if (collisionp2) {
			ball->changeDirection((eDir)((rand() % 3) + 1));
			collisionp2 = false;
			return;
		}
	}


	//5000 ms check in order to render graphics before scoring is applied.
	if (graphics::getGlobalTime() > 5000)
	{
		//add points
		// passed player2 and did not collide, player1 got point
		if ((ball->getX() > 950 - 60) && (!checkCollision())) {
			getPoint(player1);		//point to p1 //reset
			return;
		}
		// passed player1 and did not collide, player2 got point
		if ((ball->getX() < 50 + 60) && (!checkCollision())) {
			getPoint(player2);
			return;
		}

}
	//hit bottom and change direction
	if (ball->getY() == (CANVAS_HEIGHT - 10)) {
		ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
		ball->update();
	}
	//hit roof and change direction
	if (ball->getY() == 10) {
		ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
		ball->update();
	}

}

void Game::updateGameOverScreen()
{

	//ENTER BUTTON
	if (graphics::getKeyState(graphics::SCANCODE_RETURN)) {
		status = STATUS_PLAYING;
	}

}

void Game::drawGameOverScreen()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	
	graphics::stopMusic(0);

	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	char info[80];
	sprintf_s(info, "GAME OVER");
	graphics::drawText(CANVAS_WIDTH / 2 - 460, CANVAS_HEIGHT / 4, 30, info, br);
	sprintf_s(info, "WINNER:");
	graphics::drawText(CANVAS_WIDTH / 2 - 360, CANVAS_HEIGHT / 2, 27, info, br);
	if (score1 > score2)
	{
		sprintf_s(info, "Player 1");
		graphics::drawText(CANVAS_WIDTH / 2 - 430, CANVAS_HEIGHT / 2 + 70, 24, info, br);
	}
	else 
	{
		sprintf_s(info, "Player2");
		graphics::drawText(CANVAS_WIDTH / 2 - 70, CANVAS_HEIGHT / 2 + 150, 20, info, br);
	}
	



	graphics::MouseState ms;
	graphics::getMouseState(ms);

	//stigma pontikiou
	//graphics::drawDisk(window2canvasX((float)ms.cur_pos_x), window2canvasY((float)ms.cur_pos_y), 10, br);

}
void Game::drawStartScreen()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "galaxy.png";
	br.outline_opacity = 0.0f;
	//draw background
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	char info[80];
	sprintf_s(info, "Choose the level by pressing the letter and then ENTER to start!");
	graphics::drawText(CANVAS_WIDTH / 2 - 460, CANVAS_HEIGHT / 4, 30, info, br);
	sprintf_s(info, "Press 'H' for Hardcore Mode, 'M' for Medium, 'L' for Low");
	graphics::drawText(CANVAS_WIDTH / 2 - 360, CANVAS_HEIGHT / 2, 27, info, br);
	sprintf_s(info, "Player 1-> press W - S for up - down || Player 2-> press I - K for up - down");
	graphics::drawText(CANVAS_WIDTH / 2 - 430, CANVAS_HEIGHT / 2 + 70, 24, info, br);
	sprintf_s(info, "Or press ESC to quit");
	graphics::drawText(CANVAS_WIDTH / 2 - 70, CANVAS_HEIGHT / 2 + 150, 20, info, br);



	graphics::MouseState ms;
	graphics::getMouseState(ms);

	//stigma pontikiou
	//graphics::drawDisk(window2canvasX((float)ms.cur_pos_x), window2canvasY((float)ms.cur_pos_y), 10, br);

}

void Game::drawLevelScreen()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "galaxy.png";
	br.outline_opacity = 0.0f;

	//float offset = CANVAS_HEIGHT * sinf(graphics::getGlobalTime() / 1000.0f) / 4;		//kylaei to rectangle panw katw
	//draw background
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);			//orizw to kentro tou par/mou

	//draw players
	if (player1) {	//left

		if (!drawLevelScreen_initialized) {
			player1->setPosX(CANVAS_WIDTH - 950.0f);
			player1->setPosY(CANVAS_HEIGHT / 2);
		}

		player1->draw();
	}
	if (player2) {		//right

		if (!drawLevelScreen_initialized) {
			player2->setPosX(CANVAS_WIDTH - 50.0f);
			player2->setPosY(CANVAS_HEIGHT / 2);
			drawLevelScreen_initialized = true;
		}
		player2->draw();
	}


	if (ball) {
		ball->draw();
	}

	//  UI/info layer	
	if (player1 && player2) {
		char info[40];
		sprintf_s(info, "Player 1:   %.0f    ||    Player 2:   %.0f", this->score1, this->score2);
		graphics::drawText(40, 20, 20, info, br);
	}

}

void Game::update()
{
	if (status == STATUS_START) {
		updateStartScreen();
	}
	else if (status==STATUS_PLAYING) {
		updateLevelScreen();
	}
	else
	{
		updateGameOverScreen();
	}



}

void Game::draw()
{
	if (status == STATUS_START) {
		drawStartScreen();
	}
	else if (status == STATUS_PLAYING) {
		drawLevelScreen();
	}
	else
	{
		drawGameOverScreen();
	}
}

void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "orange.ttf");
	graphics::playMusic(std::string(ASSET_PATH) + "benny_hill_song.mp3", 0.5f, false, 4000);

}

float Game::window2canvasX(float x)
{
	return x * CANVAS_WIDTH / (float)window_width;
}

float Game::window2canvasY(float y)
{
	return y * CANVAS_HEIGHT / (float)window_height;
}

void Game::getPoint(Paddle* player)
{
	if (player == player1)
		score1++;
	else if (player == player2)
		score2++;

	ball->Reset();
	player1->resetY(player1);
	player2->resetY(player2);
}

Game::Game()
{
}

Game::~Game()
{
	if (player1) {
		delete player1;
	}
	if (player2) {
		delete player2;
	}
	if (ball) {
		delete ball;
	}
}

