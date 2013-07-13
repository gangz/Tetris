/*
 * ShapePlacement.cpp
 *
 *  Created on: Jul 14, 2013
 *      Author: topcoder
 */

#include "ShapePlacement.h"
#include <assert.h>

ShapePlacement::ShapePlacement(int x, int y):x(x),y(y) {
	shape = 0;
}

ShapePlacement::~ShapePlacement() {
	if (shape!=0)
		delete shape;
}

void ShapePlacement::put(Shape* shape){
	this->shape = shape;
}

void ShapePlacement::moveDown(){
	x++;
}

int ShapePlacement::shapeSize() const{
	assert(shape!=0);
	return shape->size();
}

Cell ShapePlacement::getAt(int pos) const{
	Cell c = shape->getAt(pos);
	c.x += x;
	c.y += y;
	return c;
}
