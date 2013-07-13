/*
 * GraphcisController.h
 *
 *  Created on: Jul 13, 2013
 *      Author: topcoder
 */

#ifndef GRAPHCISCONTROLLER_H_
#define GRAPHCISCONTROLLER_H_

#include "IGraphcisController.h"
class IGraphcisDriver;
class GraphcisController: public IGraphcisController {
public:
	GraphcisController(IGraphcisDriver* driver);
	virtual ~GraphcisController();
	virtual void initGUI(int area_width, int area_height);
	virtual void writeScore(int score);
	virtual void writeSpeed(int speed);
private:
	void drawMainFrame();
	void drawTetrisFrame(int area_width, int area_height);
	void drawNextShapeArea();
	IGraphcisDriver* driver;
};

#endif /* GRAPHCISCONTROLLER_H_ */
