#include "GraphcisController.h"
#include "IGraphcisDriver.h"

GraphcisController::GraphcisController(IGraphcisDriver* driver):driver(driver) {
}

GraphcisController::~GraphcisController() {
}

void GraphcisController::initGUI(int area_width, int area_height){
	drawMainFrame();
	drawTetrisFrame(area_width, area_height);
	drawNextShapeArea();
}
void GraphcisController::writeScore(int score){
	std::string s; s+=score;
	driver->writeText(Point(12,8),s);
}
void GraphcisController::writeSpeed(int speed){
	std::string s; s+=speed;
	driver->writeText(Point(12,12),s);
}

void GraphcisController::drawMainFrame(){
	driver->drawBox(Point(0,0),Point(40,24));
}
void GraphcisController::drawTetrisFrame(int area_width, int area_height){
	driver->drawBox(Point(1,1),Point(9,21));;
}
void GraphcisController::drawNextShapeArea(){
	driver->drawBox(Point(12,1),Point(17,6));
}

