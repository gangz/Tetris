/*
 * Shape.cpp
 *
 *  Created on: Jul 13, 2013
 *      Author: topcoder
 */

#include "Shape.h"
#include <assert.h>
Shape::Shape() {
	// TODO Auto-generated constructor stub

}

Shape::~Shape() {
	// TODO Auto-generated destructor stub
}

int Shape::size() const{
	return cellList.size();
}

void Shape::add(const Cell& c){
	cellList.push_back(c);
}

Cell Shape::getAt(int pos) const{
	assert (size()!=0);
	int curPos = 0;
	for(std::list<Cell>::const_iterator iter = cellList.begin();
			iter!=cellList.end();
			iter++){
		if (pos==curPos)
			return *iter;
		curPos++;
	}
	return Cell(0,0);
}
