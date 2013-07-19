#include "KeyboardInputListener.h"
#include "ncurses.h"
KeyboardInputListener::KeyboardInputListener() {
	// TODO Auto-generated constructor stub

}

KeyboardInputListener::~KeyboardInputListener() {
	// TODO Auto-generated destructor stub
}

InputListener::Instruction KeyboardInputListener::getInput(){
	int ch = getch();
	switch(ch){
	case 'q':
	case KEY_HOME:
		return InputListener::EXIST;
	case 'a':
	case KEY_LEFT:
		return InputListener::MOVE_LEFT;
	case 'd':
	case KEY_RIGHT:
		return InputListener::MOVE_RIGHT;
	case 's':
	case KEY_DOWN:
		return InputListener::MOVE_DOWN;
	case 'n':
	case 'N':
		return InputListener::NO;
	case 'y':
	case 'Y':
		return InputListener::YES;

	}
	return InputListener::IGNORE;
}
