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

void ShapePlacement::moveRight(){
	y++;
}

void ShapePlacement::moveLeft(){
	y--;
}

int ShapePlacement::shapeSize() const{
	assert(shape != 0);
	return shape->size();
}

Cell ShapePlacement::getAt(int pos) const{
	Cell c = shape->getAt(pos);
	c.x += x;
	c.y += y;
	return c;
}

void ShapePlacement::join(const ShapePlacement& rhs) {
	for (int i=0;i<rhs.shapeSize();i++){
		Cell c = rhs.getAt(i);
		Cell newCell(c.x-x,c.y-y);
		shape->add(newCell);
	}
}

int ShapePlacement::eleminate(int width_in_y){
	return shape->eleminate(width_in_y);
}

void ShapePlacement::turn(){
	shape->turn();
	return;
}
