#pragma once
#include "util.h"


class Collidable {

public:
	virtual Disk getCollisionHull() const = 0;

};

class Gameobject {

protected:
	const class Game& game;	//den to kanw me pointer giati thelw na apofygw thn periptwsh na mhn yparxei o pointer

public:
	Gameobject(const class Game& mygame);
	virtual void update() = 0;	//virtual void: it means that it does nothing, unless you make it
	virtual void draw() = 0;
	virtual void init() = 0;

};
