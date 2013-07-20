/*
 * TimerBlockMoveDown.cpp
 *
 *  Created on: 2013-7-20
 *      Author: gangz
 */

#include "TimerBlockMoveDown.h"
#include "Game.h"
GameController* _game;
TimerBlockMoveDown::TimerBlockMoveDown(GameController* game) {
	_game = game;
}

TimerBlockMoveDown::~TimerBlockMoveDown() {
}

void TimerBlockMoveDown::OnTimer(){
	_game->keyDown();
}

