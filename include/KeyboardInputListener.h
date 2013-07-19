#ifndef KEYBOARDINPUTLISTENER_H_
#define KEYBOARDINPUTLISTENER_H_

#include "IInputListener.h"

class KeyboardInputListener: public InputListener {
public:
	KeyboardInputListener();
	virtual ~KeyboardInputListener();
	virtual Instruction getInput();
};

#endif /* KEYBOARDINPUTLISTENER_H_ */
