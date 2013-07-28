/*
 * ShapeFactory.cpp
 *
 *  Created on: Jul 13, 2013
 *      Author: topcoder
 */

#include "ShapeFactory.h"




ShapeFactory::ShapeFactory() {
	srand((unsigned)time(NULL));  }

ShapeFactory::~ShapeFactory() {
}

Shape* ShapeFactory::make(){
	Shape *obj = new Shape();
	return obj;
}
Shape* ShapeFactory::makeRandom(){
	int type = rand() % (Shape::TYPE_L-Shape::TYPE_BAR+1)+ Shape::TYPE_BAR;
	return make((Shape::ShapeType)type);
}
Shape* ShapeFactory::make(Shape::ShapeType type){
	if (type== Shape::TYPE_NULL)
		return new Shape();

	return new Shape(type);

}

Shape* ShapeFactory::makeWall(int x_length, int y_length){
	Shape* shape = make();
	for (int x=0;x<x_length;x++)
	{
		shape->add(Cell(x,0));
		shape->add(Cell(x,y_length-1));
	}
	for (int y=0;y<y_length;y++)
	{
		shape->add(Cell(0,y));
		shape->add(Cell(x_length-1,y));
	}
	return shape;
}
