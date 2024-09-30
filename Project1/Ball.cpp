#include "Ball.h"
#include "graphics.h"
#include "config.h"
#include <random>
#include "util.h"
#include "game.h"

using namespace std;

void Ball::update()
{
	//EDW ALLAZEI H THESH THS MPALAS
	moveBall();
	rotation += 0.1f * graphics::getDeltaTime();
	rotation = fmodf(rotation, 360);

	if (pos_x < -size) {
		active = false;
	}

}

void Ball::draw()
{
	//skia planiti
	graphics::setOrientation(rotation);
	brush.texture = std::string(ASSET_PATH) + "planetshadow.png";
	brush.fill_opacity = 0.5f;
	brush.outline_opacity = 0.0f;
	graphics::drawRect(pos_x - 5, pos_y + 15, size, size, brush);

	//planitis
	graphics::setOrientation(rotation);


	brush.texture = std::string(ASSET_PATH) + "planet.png";


	brush.fill_opacity = 1.0f;
	//graphics::drawDisk(pos_x, pos_y, 30, brush);
	graphics::drawRect(pos_x, pos_y, size, size, brush);
	graphics::resetPose();

	if (game.getDebugMode())		//to game den htan accesible sto epipedo tou paikth giati sto epipedo tou game to eixame orisei san eswterikh metavlhth
	{								//(ara htan private)opote den mporousan oi klhronomoi na to doun, gia ayto to epanaprosdiorisame ws protected
		graphics::Brush br;			//*edw ftiaxnoume kainourio brush, giati den thelw thn hdh yparxousa metavlhth tou Enemy alla nea, eswterikh
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.3f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.3f;
		br.gradient = false;
		Disk hull = getCollisionHull();		//gia na mas deixnei thn trexousa thesh tou paikth
		graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);

	}

}

void Ball::init()
{
	pos_x = CANVAS_WIDTH + 1.1f * size;
	pos_y = CANVAS_HEIGHT * rand0to1();
	size = 50;
	rotation = 360 * rand0to1();
	brush.outline_opacity = 0.0f;
	randomDirection();
}

void Ball::Reset()
{
	pos_x = originalX;
	pos_y = originalY;
	randomDirection();
	//direction = STOP;
}

void Ball::randomDirection()
{
	direction = (eDir)((rand() % 6) + 1);
}

void Ball::changeDirection(eDir d)
{
	direction = d;
}

void Ball::moveBall()
{
	float deltaSpeed = speed * graphics::getDeltaTime();

	switch (direction)
	{
	case STOP:
		break;
	case LEFT:
		pos_x -= deltaSpeed;
		break;
	case RIGHT:
		pos_x += deltaSpeed;
		break;
	case UPLEFT:
		pos_x -= deltaSpeed; pos_y -= deltaSpeed;
		break;
	case DOWNLEFT:
		pos_x -= deltaSpeed; pos_y += deltaSpeed;
		break;
	case UPRIGHT:
		pos_x += deltaSpeed; pos_y -= deltaSpeed;
		break;
	case DOWNRIGHT:
		pos_x += deltaSpeed; pos_y += deltaSpeed;
		break;
	default:
		break;
	}
}

Ball::Ball(const Game& mygame, float gameLevel)
	:Gameobject(mygame)
{
	init();
	this->speed = gameLevel;
}

Ball::~Ball()
{

}


Disk Ball::getCollisionHull() const
{
	Disk disk{};
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = size * 0.2f;

	return disk;
}

