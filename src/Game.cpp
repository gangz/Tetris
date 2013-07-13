#include "Game.h"
#include "IPainter.h"
Game::Game(IPainter* painter):painter(painter) {

}

Game::~Game() {
}

void Game::init(){
	//painter->drawMainFrame();
	painter->drawTetrisFrame(8,20);
	painter->drawNextShapeArea();
	painter->writeScore(0);
	painter->writeSpeed(0);
}
