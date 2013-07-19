#ifndef ICOLLISIONDETECTOR_H_
#define ICOLLISIONDETECTOR_H_

#include "IInputListener.h"
class ShapePlacement;
class ICollisionDetector {
public:
	virtual ~ICollisionDetector(){};
    virtual bool isCollision(ShapePlacement* moveObj, ShapePlacement* stillObj, InputListener::Instruction direction) = 0;
};

#endif /* COLLISIONDETECTOR_H_ */
