#ifndef IINPUTLISTENER_H_
#define IINPUTLISTENER_H_

class InputListener{
public:
	typedef enum {
		EXIST=1,
		MOVE_LEFT,
		MOVE_RIGHT,
		MOVE_DOWN
	}Instruction;
	virtual ~InputListener(){};
	virtual Instruction getInput()=0;
};


#endif /* IINPUTLISTENER_H_ */
