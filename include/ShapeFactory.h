/*
 * ShapeFactory.h
 *
 *  Created on: Jul 13, 2013
 *      Author: topcoder
 */

#ifndef SHAPEFACTORY_H_
#define SHAPEFACTORY_H_
#include "Shape.h"
class ShapeFactory {
public:
	typedef enum {
		TYPE_NULL,
		TYPE_BAR,
	}ShapeType;

public:
	ShapeFactory();
	virtual ~ShapeFactory();
	Shape* make(){
		Shape *obj = new Shape();
		return obj;
	}
	Shape* make(ShapeType type){
		Shape* shape = make();

		if (type==TYPE_BAR)
		{
			shape->add(Cell(0,0));
			shape->add(Cell(0,1));
			shape->add(Cell(0,2));
			shape->add(Cell(0,3));
		}
		return shape;
	}

	Shape* makeWall(int x_length, int y_length){
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

};


#endif /* SHAPEFACTORY_H_ */
