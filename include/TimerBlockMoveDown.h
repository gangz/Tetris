/*
 * TimerBlockMoveDown.h
 *
 *  Created on: 2013-7-20
 *      Author: gangz
 */

#ifndef TIMERBLOCKMOVEDOWN_H_
#define TIMERBLOCKMOVEDOWN_H_

#include "CTimer.h"
class GameController;
class TimerBlockMoveDown: public CTimer {
public:
	TimerBlockMoveDown(GameController* game);
	virtual ~TimerBlockMoveDown();
	virtual void OnTimer();
};

#endif /* TIMERBLOCKMOVEDOWN_H_ */
