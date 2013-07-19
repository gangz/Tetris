
#ifndef NULLINPUTLISTENER_H_
#define NULLINPUTLISTENER_H_

#include "IInputListener.h"

class NullInputListener:public InputListener{
public:
	virtual ~NullInputListener(){};
	virtual Instruction getInput(){
		return InputListener::EXIST;
	};

};


#endif /* NULLINPUTLISTENER_H_ */
