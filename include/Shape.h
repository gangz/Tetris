/*
 * Shape.h
 *
 *  Created on: Jul 13, 2013
 *      Author: topcoder
 */

#ifndef SHAPE_H_
#define SHAPE_H_
#include <list>




class Cell{
public:
	Cell(int x, int y):x(x),y(y){};
	int x;
	int y;
};
class Shape {
public:
	typedef enum {
		TYPE_BAR,
		TYPE_SQUARE,
		TYPE_T,
		TYPE_INV_Z,
		TYPE_INV_L,
		TYPE_Z,
		TYPE_L,
		TYPE_NULL,
	}ShapeType;

	Shape();
	virtual ~Shape();
	Shape(ShapeType shapeType);
	int size() const;
	void add(const Cell& c);
	Cell getAt(int pos)  const;
	int eleminate(int width_in_y);
	void turn();
private:
	std::list<Cell> cellList;
	ShapeType shapeType;
	int rotationIndex;
};

#endif /* SHAPE_H_ */
