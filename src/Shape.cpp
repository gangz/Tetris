#include "Shape.h"
#include <assert.h>
#include <map>
#include <algorithm>
int shape_data[][4][2]={
		{{0,0},{0,1},{0,2},{0,3}}, //BAR
		{{0,2},{1,2},{2,2},{3,2}}, //BAR
		{{0,0},{0,1},{0,2},{0,3}}, //BAR
		{{0,2},{1,2},{2,2},{3,2}}, //BAR
		{{0,0},{0,1},{1,0},{1,1}}, //SQUARE
		{{0,0},{0,1},{1,0},{1,1}}, //SQUARE
		{{0,0},{0,1},{1,0},{1,1}}, //SQUARE
		{{0,0},{0,1},{1,0},{1,1}}, //SQUARE
		{{0,0},{0,1},{1,1},{1,2}}, //Z
		{{0,1},{1,0},{1,1},{2,0}}, //Z
		{{0,0},{0,1},{1,1},{1,2}}, //Z
		{{0,1},{1,0},{1,1},{2,0}}, //Z
		{{0,0},{0,1},{0,2},{1,2}}, //L
		{{0,1},{1,1},{2,1},{2,0}}, //L
		{{0,0},{1,0},{1,1},{1,2}}, //L
		{{0,0},{0,1},{1,0},{2,0}}, //L
		{{0,1},{0,2},{1,0},{1,1}}, //INV_Z
		{{0,0},{1,0},{1,1},{2,1}}, //INV_Z
		{{0,1},{0,2},{1,0},{1,1}}, //INV_Z
		{{0,0},{1,0},{1,1},{2,1}}, //INV_Z
		{{0,0},{0,1},{0,2},{1,0}}, //INV_L
		{{0,0},{1,0},{2,0},{2,1}}, //INV_L
		{{1,0},{1,1},{1,2},{0,2}}, //INV_L
		{{0,0},{0,1},{1,1},{2,1}}, //INV_L
		{{0,0},{0,1},{0,2},{1,1}}, //T
		{{0,0},{1,0},{2,0},{1,1}}, //T
		{{1,0},{1,1},{1,2},{0,1}}, //T
		{{0,1},{1,1},{2,1},{1,0}}, //T

};

Shape::Shape() {
	shapeType = TYPE_NULL;
	rotationIndex = 0;
}

Shape::~Shape() {
	// TODO Auto-generated destructor stub
}

Shape::Shape(ShapeType shapeType){
	rotationIndex = 0;
	this->shapeType =shapeType;

	int index = (int)shapeType * 4+rotationIndex;
	for (int i=0;i<4;i++){
		add(Cell(shape_data[index][i][0],shape_data[index][i][1]));
	}
}

void Shape::turn(){
//	assert(shapeType>=TYPE_BAR && shapeType<=TYPE_T);

	rotationIndex = rotationIndex++;
	rotationIndex %= 4;

	int index = (int)shapeType * 4+rotationIndex;

//	assert(index>=0 && index<=28);
	cellList.clear();
	for (int i=0;i<4;i++){
		add(Cell(shape_data[index][i][0],shape_data[index][i][1]));
	}
}

int Shape::size() const{
	return cellList.size();
}

void Shape::add(const Cell& c){
	cellList.push_back(c);
}

Cell Shape::getAt(int pos) const{
	assert (size()!=0);
	assert (pos<size());
	int curPos = 0;
	for(std::list<Cell>::const_iterator iter = cellList.begin();
			iter!=cellList.end();
			iter++){
		if (pos==curPos)
			return *iter;
		curPos++;
	}
	assert(false); //should never reach here
	return Cell(0,0);
}

void countAllRows(std::map<int, int>& rowCounts,
		std::list<Cell> cellList) {
	std::map<int,int>::iterator count_iter;
	for (std::list<Cell>::const_iterator iter = cellList.begin();
			iter != cellList.end(); iter++) {
		int x = iter->x;
		count_iter = rowCounts.find(x);
		if (count_iter != rowCounts.end()) {
			count_iter->second += 1;
		} else {
			rowCounts.insert(std::pair<int, int>(x, 1));
		}
	}
}

void removeRow(std::list<Cell> cellList, int row_index){

}
struct Compare: public std::binary_function<Cell, Cell, bool>
{
    bool operator ()(const Cell& lhs, const Cell& rhs) const
    { return lhs.x == rhs.x; }
};

int Shape::eleminate(int width_in_y){
	std::map<int,int> rowCounts;
	countAllRows(rowCounts, cellList);

	int removedRowsCount = 0;
	for (std::map<int,int>::iterator count_iter=rowCounts.begin();count_iter!=rowCounts.end();count_iter++){
		if (count_iter->second==width_in_y){
			std::list<Cell>::iterator iter = std::remove_if(cellList.begin(),cellList.end(),
					bind2nd(Compare(), Cell(count_iter->first,0)));
			cellList.erase(iter, cellList.end());

			for(iter=cellList.begin();iter!=cellList.end();iter++){
				if (iter->x < count_iter->first)
					iter->x++;
			}

			removedRowsCount++;
		}
	}

	return removedRowsCount;
}

