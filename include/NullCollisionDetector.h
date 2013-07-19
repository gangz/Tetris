#ifndef NULLCOLLISIONDECTOR_H_
#define NULLCOLLISIONDECTOR_H_

#include "ICollisionDetector.h"

class NullCollisionDector:public ICollisionDetector{
public:
	virtual ~NullCollisionDector(){};
	virtual bool isCollision(ShapePlacement* first, ShapePlacement* second, InputListener::Instruction direction){
		return false;
	};
};


#endif /* NULLCOLLISIONDECTOR_H_ */
