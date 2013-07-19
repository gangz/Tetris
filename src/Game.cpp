#include "Game.h"
#include "IGraphcisController.h"
#include "Shape.h"
#include "ShapeFactory.h"
#include "ShapePlacement.h"
#include "IInputListener.h"
#include "ICollisionDetector.h"

GameController::GameController(IGraphcisController* graphcisController,
		InputListener* inputController,
		ICollisionDetector* collisionDetector):graphcisController(graphcisController) ,
		inputListener(inputController),
		collisionDetector(collisionDetector){
	activeShapePlacement = new ShapePlacement(0,0);
	borderShapePlacement = new ShapePlacement(-1,-1);
	existedBlockPlacement = new ShapePlacement(0,0);
	ShapeFactory shapeFactory;
	existedBlockPlacement->put(shapeFactory.make(ShapeFactory::TYPE_NULL));
	borderShapePlacement->put(shapeFactory.makeWall(22,10));
}

GameController::~GameController() {
	if (activeShapePlacement!=0)
		delete activeShapePlacement;
	delete borderShapePlacement;
	delete existedBlockPlacement;
}

void GameController::init(){
	graphcisController->initGUI(8,20);
	graphcisController->writeScore(0);
	graphcisController->writeSpeed(0);
}

void GameController::reDraw() {
	graphcisController->cleanTetrisArea();
	graphcisController->drawShape(activeShapePlacement);
	graphcisController->drawShape(existedBlockPlacement);
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
	if (collisionDetector->isCollision(activeShapePlacement,borderShapePlacement,InputListener::MOVE_DOWN)||
			collisionDetector->isCollision(activeShapePlacement,existedBlockPlacement,InputListener::MOVE_DOWN))
	{
		existedBlockPlacement->join(*activeShapePlacement);
		delete activeShapePlacement;
		activeShapePlacement = new ShapePlacement(0,0);
		createShape();
		return;
	}
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


