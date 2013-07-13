#include "Game.h"
#include "IGraphcisController.h"
#include "Shape.h"
#include "ShapeFactory.h"
Game::Game(IGraphcisController* graphcisController):graphcisController(graphcisController) {
	activeShape = 0;
}

Game::~Game() {
	if (activeShape!=0)
		delete activeShape;
}

void Game::init(){
	graphcisController->initGUI(8,20);
	graphcisController->writeScore(0);
	graphcisController->writeSpeed(0);
}

void Game::start(){
	ShapeFactory shapeFactory;
	activeShape = shapeFactory.make(ShapeFactory::TYPE_BAR);
	graphcisController->drawShape(activeShape);
}
