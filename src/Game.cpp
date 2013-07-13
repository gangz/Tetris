#include "Game.h"
#include "IGraphcisController.h"
Game::Game(IGraphcisController* graphcisController):graphcisController(graphcisController) {

}

Game::~Game() {
}

void Game::init(){
	graphcisController->initGUI(8,20);
	graphcisController->writeScore(0);
	graphcisController->writeSpeed(0);
}

void Game::start(){
	Shape shape;
	graphcisController->drawShape(shape);
}
