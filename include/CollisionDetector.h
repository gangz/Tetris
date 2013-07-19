#ifndef COLLISIONDETECTOR_H_
#define COLLISIONDETECTOR_H_

#include "ICollisionDetector.h"

class CollisionDetector: public ICollisionDetector {
public:
	CollisionDetector();
	virtual ~CollisionDetector();
    virtual bool isCollision(ShapePlacement* moveObj, ShapePlacement* stillObj, InputListener::Instruction direction);

};

#endif /* COLLISIONDETECTOR_H_ */
