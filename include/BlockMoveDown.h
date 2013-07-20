/*
 * BlockMoveDown.h
 *
 *  Created on: 2013-7-20
 *      Author: gangz
 */

#ifndef BLOCKMOVEDOWN_H_
#define BLOCKMOVEDOWN_H_

#include "ITimerEventListener.h"
class GameController;
class BlockMoveDown: public ITimerEventListener {
public:
	BlockMoveDown(GameController* game);
	virtual ~BlockMoveDown();
	virtual void timeOut();
private:
	GameController* game;
};

#endif /* BLOCKMOVEDOWN_H_ */
