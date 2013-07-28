/*
 * ShapeFactory.h
 *
 *  Created on: Jul 13, 2013
 *      Author: topcoder
 */

#ifndef SHAPEFACTORY_H_
#define SHAPEFACTORY_H_
#include "Shape.h"
#include "stdlib.h"
#include <time.h>

class ShapeFactory {
public:
	ShapeFactory();

	virtual ~ShapeFactory();
	Shape* make();
	Shape* makeRandom();
	Shape* make(Shape::ShapeType type);

	Shape* makeWall(int x_length, int y_length);

};


#endif /* SHAPEFACTORY_H_ */
