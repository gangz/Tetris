#include "Game.h"
#include "IGraphcisController.h"
#include "Shape.h"
#include "ShapeFactory.h"
#include "ShapePlacement.h"
#include "IInputListener.h"
Game::Game(IGraphcisController* graphcisController,
		InputListener* inputController):graphcisController(graphcisController) ,
		inputListener(inputController){
	activeShapePlacement = new ShapePlacement(0,0);
}

Game::~Game() {
	if (activeShapePlacement!=0)
		delete activeShapePlacement;
	//delete graphcisController;
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

void Game::listenInputEvents(){
	if (inputListener!=0){
		InputListener::Instruction instruct;
		do {
			instruct = inputListener->getInput();
			switch(instruct){
			case InputListener::MOVE_DOWN:
				keyDown();break;
			case InputListener::MOVE_LEFT:
				keyLeft();break;
			case InputListener::MOVE_RIGHT:
				keyRight();break;
			}
		}
		while(instruct!=InputListener::EXIST);
	}
}

void Game::createShape(){
	ShapeFactory shapeFactory;
	Shape* activeShape = shapeFactory.make(ShapeFactory::TYPE_BAR);
	activeShapePlacement->put(activeShape);
}
void Game::start(){
	createShape();
	reDraw();
	listenInputEvents();
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


