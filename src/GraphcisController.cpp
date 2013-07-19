#include "GraphcisController.h"
#include "IGraphcisDriver.h"
#include "ShapePlacement.h"
#include <stdio.h>
#include "Shape.h"
const int TETRIS_POS_V = 1;
const int TETRIS_POS_H = 1;
const int TETRIS_WIDTH = 8;
const int TETRIS_HEIGHT = 20;

const int NEXT_BLOCK_AREA_V = TETRIS_POS_V;
const int NEXT_BLOCK_AREA_H = TETRIS_POS_H + TETRIS_WIDTH + 3;
const int NEXT_BLOCK_WIDTH = 5;
const int NEXT_BLOCK_HEIGHT = 5;

const int SCORE_AREA_V = NEXT_BLOCK_AREA_V+NEXT_BLOCK_HEIGHT+3;
const int SCORE_AREA_H = NEXT_BLOCK_AREA_H;
const int SCORE_WIDTH = NEXT_BLOCK_WIDTH;
const int SCORE_HEIGHT = 2;

const int SPEED_AREA_V = SCORE_AREA_V+SCORE_HEIGHT+3;
const int SPEED_AREA_H = NEXT_BLOCK_AREA_H;
const int SPEED_WIDTH = NEXT_BLOCK_WIDTH;
const int SPEED_HEIGHT = 2;
//TODO: GraphcisController can delegate it's responsibility
//      to Tetris, Score, Speed, ... objects.

GraphcisController::GraphcisController(IGraphcisDriver* driver):driver(driver) {
}

GraphcisController::~GraphcisController() {
}

void GraphcisController::initGUI(int area_width, int area_height){
	drawMainFrame();
	drawTetrisFrame(area_width, area_height);
	drawNextShapeArea();
	drawScoreArea();
	drawSpeedArea();
}
void GraphcisController::writeScore(int score){
	char str[20];
	sprintf(str,"%d",score);
	std::string s(str);
	driver->writeText(Point(SCORE_AREA_V+2,SCORE_AREA_H+3),s);
}
void GraphcisController::writeSpeed(int speed){
	char str[20];
	sprintf(str,"%d",speed);
	std::string s(str);
	driver->writeText(Point(SPEED_AREA_V+2,SPEED_AREA_H+3),s);
}

void GraphcisController::drawMainFrame(){
//	driver->drawBox(Point(0,0),Point(40,24));
}


void GraphcisController::drawTetrisFrame(int area_width, int area_height){
	driver->drawBox(Point(TETRIS_POS_V,TETRIS_POS_H),
			Point(TETRIS_POS_V+TETRIS_HEIGHT,TETRIS_POS_H+TETRIS_WIDTH));;
}
void GraphcisController::drawNextShapeArea(){
	driver->drawBox(Point(NEXT_BLOCK_AREA_V,NEXT_BLOCK_AREA_H),
			Point(NEXT_BLOCK_AREA_V+NEXT_BLOCK_HEIGHT,
					NEXT_BLOCK_AREA_H+NEXT_BLOCK_WIDTH));
}

void GraphcisController::drawScoreArea(){
	driver->drawBox(Point(SCORE_AREA_V,SCORE_AREA_H),
			Point(SCORE_AREA_V+SCORE_HEIGHT,SCORE_AREA_H+SCORE_WIDTH));
	driver->writeText(Point(SCORE_AREA_V,SCORE_AREA_H+1),"score");
}

void GraphcisController::drawSpeedArea(){
	driver->drawBox(Point(SPEED_AREA_V,SPEED_AREA_H),
			Point(SPEED_AREA_V+SPEED_HEIGHT,SPEED_AREA_H+SPEED_WIDTH));
	driver->writeText(Point(SPEED_AREA_V,SPEED_AREA_H+1),"speed");
}

void GraphcisController::drawShape(const ShapePlacement* const shape){
	for (int i=0;i < shape->shapeSize();i++){
		Cell c = shape->getAt(i);
		driver->drawCell(Point(TETRIS_POS_V+1+c.x,
				      TETRIS_POS_H + 1 +c.y));
	}
}

void GraphcisController::cleanTetrisArea(){
	for(int c = TETRIS_POS_V+1;c<TETRIS_POS_V+1+TETRIS_HEIGHT;c++)
		for (int r = TETRIS_POS_H+1; r<TETRIS_POS_H+1+TETRIS_WIDTH; r++)
			driver->writeText(Point(c,r),"  ");
}

void GraphcisController::drawGameOver(){
	int v_1 = TETRIS_POS_V+6;
	int v_2 = v_1+4;
	int h_1 = TETRIS_POS_H;
	int h_2 = h_1+ 18;
	for(int c = h_1;c<=h_2;c++)
		for (int r = v_1; r<=v_2; r++)
			driver->writeText(Point(r,c),"  ");
	driver->drawBox(Point(v_1,h_1),
			Point(v_2,h_2));
	driver->writeText(Point(v_1+3,h_1+2),"Game Over. Start a new Game(Y/N)?");
}


