#include "Game.h"
#include "IGraphcisController.h"
#include "Shape.h"
#include "ShapeFactory.h"
#include "ShapePlacement.h"
#include "IInputListener.h"
#include "ICollisionDetector.h"
#include "stdlib.h"

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
	terminateFlag = false;
}

void GameController::clean() {
	if (activeShapePlacement != 0)
		delete activeShapePlacement;

	delete borderShapePlacement;
	delete existedBlockPlacement;
}

GameController::~GameController() {
	clean();
}

void GameController::restart(){
	clean();

	activeShapePlacement = new ShapePlacement(0,0);
	borderShapePlacement = new ShapePlacement(-1,-1);
	existedBlockPlacement = new ShapePlacement(0,0);
	ShapeFactory shapeFactory;
	existedBlockPlacement->put(shapeFactory.make(ShapeFactory::TYPE_NULL));
	borderShapePlacement->put(shapeFactory.makeWall(22,10));
	terminateFlag = false;

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
	graphcisController->writeScore(_scoreKeeper.score());
}

void GameController::listenInputEvents(){
	InputListener::Instruction instruct;
	do {
		if (terminateFlag) break;
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

void GameController::terminate(){
	terminateFlag = true;
}

bool GameController::checkGameOver() {
	if (existedBlockPlacement->shapeSize()==0) return false;
	Cell c =existedBlockPlacement->getAt(existedBlockPlacement->shapeSize()-1);
	if (c.x == 0) {
		graphcisController->drawGameOver();
		InputListener::Instruction instruct;
		inputListener->getInput();
		if (instruct == InputListener::NO) {
			terminate();
		} else if (instruct == InputListener::YES) {
			restart();
		}
		return true;
	}
	return false;
}

void GameController::eleminateRows() {
	int rows = existedBlockPlacement->eleminate(8);
	_scoreKeeper.eleminateRows(rows);
}

void GameController::fallDownExistShape() {
	while(!collisionDetector->isCollision(existedBlockPlacement,borderShapePlacement,InputListener::MOVE_DOWN))
		existedBlockPlacement->moveDown();
}

void GameController::moveDownCollision() {
	existedBlockPlacement->join(*activeShapePlacement);
	eleminateRows();
	fallDownExistShape();
	if (checkGameOver()) return;
	delete activeShapePlacement;
	activeShapePlacement = new ShapePlacement(0, 0);
	createShape();
}

void GameController::keyDown(){
	if (collisionDetector->isCollision(activeShapePlacement,borderShapePlacement,InputListener::MOVE_DOWN)||
			collisionDetector->isCollision(activeShapePlacement,existedBlockPlacement,InputListener::MOVE_DOWN))
	{
		moveDownCollision();
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


