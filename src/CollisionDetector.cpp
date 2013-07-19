#include "CollisionDetector.h"
#include "ShapePlacement.h"
#include <assert.h>

CollisionDetector::CollisionDetector() {
	// TODO Auto-generated constructor stub

}

CollisionDetector::~CollisionDetector() {
	// TODO Auto-generated destructor stub
}

bool CollisionDetector::isCollision(ShapePlacement* moveObj, ShapePlacement* stillObj, InputListener::Instruction direction)
{

	int offset[][2]={{0,-1},{0,1},{1,0}};
	int index = direction-InputListener::MOVE_LEFT;
	assert(index<=2 && index>=0);

	for (int i=0;i<moveObj->shapeSize();i++)
	{
		Cell cellMove = moveObj->getAt(i);
		for (int j=0;j<stillObj->shapeSize();j++){
			Cell cellStill = stillObj->getAt(j);
			if (cellMove.x+offset[index][0] == cellStill.x &&
				cellMove.y+offset[index][1]  == cellStill.y)
				return true;
		}
	}
	return false;
}
