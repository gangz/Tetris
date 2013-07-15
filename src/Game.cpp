#include "Game.h"
#include "IGraphcisController.h"
#include "Shape.h"
#include "ShapeFactory.h"
#include "ShapePlacement.h"
#include "IInputController.h"
Game::Game(IGraphcisController* graphcisController,
		InputController* inputController):graphcisController(graphcisController) ,
		inputController(inputController){
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

void Game::reDraw() {
	graphcisController->cleanTetrisArea();
	graphcisController->drawShape(activeShapePlacement);
}

void Game::start(){
	ShapeFactory shapeFactory;
	Shape* activeShape = shapeFactory.make(ShapeFactory::TYPE_BAR);
	activeShapePlacement->put(activeShape);
	reDraw();
}

void Game::keyDown(){
	activeShapePlacement->moveDown();
	reDraw();
}

void Game::keyLeft(){
	activeShapePlacement->moveLeft();
	reDraw();
}

void Game::keyRight(){
	activeShapePlacement->moveRight();
	reDraw();
}


