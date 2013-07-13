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
	;
}
void GraphcisController::writeSpeed(int speed){
	;
}

void GraphcisController::drawMainFrame(){
	driver->drawBox(Point(0,0),Point(40,24));
}
void GraphcisController::drawTetrisFrame(int area_width, int area_height){
	;
}
void GraphcisController::drawNextShapeArea(){
	;
}

