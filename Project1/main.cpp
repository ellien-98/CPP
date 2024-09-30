#include "game.h"
#include "graphics.h"
#include "config.h"
//#include <iostream>
//#include <time.h>
//#include <conio.h>

//using namespace std;
//old:
//enumeration of direction


void resize(int w, int h) {
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    game->setWindowDimension((unsigned int)w, (unsigned int)h);        //exw enhmerwwwmenh thn katastash tou parathyrou mesa sto frame object
}

void update(float ms) {             //einai callbacks kai kalountai mones tous
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());        //enas void pointer prepei na parei cast gia na ginei sygkekrienow pointer
    game->update();
}

// The window content drawing function.
void draw() {
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    game->draw();
}

int main()
{
    Game mygame;


    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Ping Pong Game");

    graphics::setUserData(&mygame);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    //mygame.setDebugMode(false);
    mygame.init();
    //otan to kanw set-> true blepw ta collisionHulls twn objects
    mygame.setDebugMode(false);
    graphics::startMessageLoop();       //this loop calls game and init whenever it is needed (->callbacks)


    return 0;
}