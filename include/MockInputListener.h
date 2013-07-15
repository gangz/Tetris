/*
 * MockInputListener.h
 *
 *  Created on: Jul 15, 2013
 *      Author: topcoder
 */

#ifndef MOCKINPUTLISTENER_H_
#define MOCKINPUTLISTENER_H_
#include "IInputListener.h"

class MockInputListener:public InputListener{
public:
	virtual ~MockInputListener(){};
	virtual Instruction getInput(){
		mock().actualCall("InputListener::getInput")
			  .onObject(this);
        return (Instruction)(mock().intReturnValue());
	};

};

#endif /* MOCKINPUTLISTENER_H_ */
