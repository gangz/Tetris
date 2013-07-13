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
	Shape();
	virtual ~Shape();
	int size() const;
	void add(const Cell& c);
	Cell getAt(int pos)  const;
private:
	std::list<Cell> cellList;
};

#endif /* SHAPE_H_ */
