#include "Game.h"
#include "IGraphcisController.h"
#include "Shape.h"
#include "ShapeFactory.h"
#include "ShapePlacement.h"
#include "IInputListener.h"
#include "CollisionDetector.h"

GameController::GameController(IGraphcisController* graphcisController,
		InputListener* inputController,
		ICollisionDetector* collisionDetector):graphcisController(graphcisController) ,
		inputListener(inputController),
		collisionDetector(collisionDetector){
	activeShapePlacement = new ShapePlacement(0,0);
	borderShapePlacement = 0;
}

GameController::~GameController() {
	if (activeShapePlacement!=0)
		delete activeShapePlacement;
}

void GameController::init(){
	graphcisController->initGUI(8,20);
	graphcisController->writeScore(0);
	graphcisController->writeSpeed(0);
}

void GameController::reDraw() {
	graphcisController->cleanTetrisArea();
	graphcisController->drawShape(activeShapePlacement);
}

void GameController::listenInputEvents(){
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

void GameController::createShape(){
	ShapeFactory shapeFactory;
	Shape* activeShape = shapeFactory.make(ShapeFactory::TYPE_BAR);
	activeShapePlacement->put(activeShape);

}
void GameController::start(){
	createShape();
	reDraw();
	listenInputEvents();
}

void GameController::keyDown(){
	if (collisionDetector->isCollision(activeShapePlacement,borderShapePlacement,InputListener::MOVE_DOWN))
		return;
	activeShapePlacement->moveDown();
	reDraw();
}

void GameController::keyLeft(){
	if (collisionDetector->isCollision(activeShapePlacement,borderShapePlacement,InputListener::MOVE_LEFT))
		return;
	activeShapePlacement->moveLeft();
	reDraw();
}

void GameController::keyRight(){
	if (collisionDetector->isCollision(activeShapePlacement,borderShapePlacement,InputListener::MOVE_RIGHT))
		return;
	activeShapePlacement->moveRight();
	reDraw();
}


