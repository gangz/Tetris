#include "GraphcisController.h"
#include "IGraphcisDriver.h"
#include <stdio.h>
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
	driver->writeText(Point(11,15),s);
}
void GraphcisController::writeSpeed(int speed){
	char str[20];
	sprintf(str,"%d",speed);
	std::string s(str);
	driver->writeText(Point(16,15),s);
}

void GraphcisController::drawMainFrame(){
//	driver->drawBox(Point(0,0),Point(40,24));
}
void GraphcisController::drawTetrisFrame(int area_width, int area_height){
	driver->drawBox(Point(1,1),Point(21,9));;
}
void GraphcisController::drawNextShapeArea(){
	driver->drawBox(Point(1,12),Point(6,17));
}

void GraphcisController::drawScoreArea(){
	driver->drawBox(Point(9,12),Point(11,17));
	driver->writeText(Point(9,13),"score");
}

void GraphcisController::drawSpeedArea(){
	driver->drawBox(Point(14,12),Point(16,17));
	driver->writeText(Point(14,13),"speed");
}


