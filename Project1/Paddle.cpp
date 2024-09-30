#include "Paddle.h"
#include "graphics.h"
#include "game.h"
#include "util.h"

Paddle::Paddle(const Game& mygame)		//ara emathe kai o player to mygame(prepei na to mathoun oles oi klaseis-kai o meteorite-
	: Gameobject(mygame)
{
	init();
}


void Paddle::update()
{

	if (pos_x < 0) pos_x = 50;
	if (pos_x > CANVAS_WIDTH) pos_x = CANVAS_WIDTH - 40;
	if (pos_y < 0) pos_y = 50;
	if (pos_y > CANVAS_HEIGHT) pos_y = CANVAS_HEIGHT - 40;

}

void Paddle::draw()
{

	//player1
	graphics::Brush br;

	//EMFANISH BARAS
	graphics::setOrientation(-90.f); //STRIPSIMO KATHETA ANTI GIA ORIZONTIA TOY ANTIKEIMENOY
	graphics::setScale(height, height); //MEGENTINSH OMOIMORFHH
	br.fill_opacity = 1.0f;
	br.outline_opacity = 0.0f; //xwris perigramma
	br.texture = std::string(ASSET_PATH) + "playerbar.png";
	graphics::drawRect(pos_x, pos_y, 180, 60, br);


	if (game.getDebugMode())		//to game den htan accesible sto epipedo tou paikth giati sto epipedo tou game to eixame orisei san eswterikh metavlhth
	{								//(ara htan private)opote den mporousan oi klhronomoi na to doun, gia ayto to epanaprosdiorisame ws protected
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 0.3f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.3f;
		br.gradient = false;
		Disk hull = getCollisionHull();		//gia na mas deixnei thn trexousa thesh tou paikth
		graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);

	}

}

void Paddle::init()
{
	pos_x = CANVAS_WIDTH / 10;
	pos_y = CANVAS_HEIGHT / 8;
}

void Paddle::resetY(Paddle* player)
{
	player->setPosY(CANVAS_HEIGHT / 2);

}

void Paddle::upwards()
{
	this->pos_y -= speed * graphics::getDeltaTime() / 10.0f;
	this->update();
}

void Paddle::downwards()
{
	this->pos_y += speed * graphics::getDeltaTime() / 10.0f;
	this->update();

}

Disk Paddle::getCollisionHull() const
{
	Disk disk{};
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = 0.0f;

	return disk;
}


