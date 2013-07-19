#ifndef NULLCOLLISIONDECTOR_H_
#define NULLCOLLISIONDECTOR_H_

#include "ICollisionDetector.h"

class NullCollisionDetector:public ICollisionDetector{
public:
	virtual ~NullCollisionDetector(){};
	virtual bool isCollision(ShapePlacement* moveObj, ShapePlacement* stillObj, InputListener::Instruction direction){
		return false;
	};
};


#endif /* NULLCOLLISIONDECTOR_H_ */
