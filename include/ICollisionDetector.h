#ifndef COLLISIONDETECTOR_H_
#define COLLISIONDETECTOR_H_

#include "IInputListener.h"
class ShapePlacement;
class ICollisionDetector {
public:
	virtual ~ICollisionDetector(){};
    virtual bool isCollision(ShapePlacement* first, ShapePlacement* second, InputListener::Instruction direction) = 0;
};

#endif /* COLLISIONDETECTOR_H_ */
