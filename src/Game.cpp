#include "Game.h"
#include "IGraphcisController.h"
#include "Shape.h"
#include "ShapeFactory.h"
#include "ShapePlacement.h"
Game::Game(IGraphcisController* graphcisController):graphcisController(graphcisController) {
	activeShapePlacement = new ShapePlacement(0,0);
}

Game::~Game() {
	if (activeShapePlacement!=0)
		delete activeShapePlacement;
}

void Game::init(){
	graphcisController->initGUI(8,20);
	graphcisController->writeScore(0);
	graphcisController->writeSpeed(0);
}

void Game::start(){
	ShapeFactory shapeFactory;
	Shape* activeShape = shapeFactory.make(ShapeFactory::TYPE_BAR);
	activeShapePlacement->put(activeShape);
	graphcisController->drawShape(activeShapePlacement);
}
