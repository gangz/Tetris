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
		TYPE_BAR = 0,
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

};


#endif /* SHAPEFACTORY_H_ */
