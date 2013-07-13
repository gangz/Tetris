/*
 * ShapePlacement.h
 *
 *  Created on: Jul 14, 2013
 *      Author: topcoder
 */

#ifndef SHAPEPLACEMENT_H_
#define SHAPEPLACEMENT_H_
#include "Shape.h"

class ShapePlacement {
public:
	ShapePlacement(int x, int y);
	virtual ~ShapePlacement();
	void put(Shape* shape);
	void moveDown();
	int shapeSize() const;
	Cell getAt(int pos) const;
private:
	Shape* shape;
	int x;
	int y;
};

#endif /* SHAPEPLACEMENT_H_ */
