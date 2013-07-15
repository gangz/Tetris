/*
 * IInputController.h
 *
 *  Created on: Jul 15, 2013
 *      Author: topcoder
 */

#ifndef IINPUTCONTROLLER_H_
#define IINPUTCONTROLLER_H_

class InputController{
public:
	typedef enum {
		EXIST,
		MOVE_LEFT,
		MOVE_RIGHT,
		MOVE_DOWN

	}Instruction;
	virtual ~InputController(){};
	virtual Instruction getInput()=0;
};


#endif /* IINPUTCONTROLLER_H_ */
