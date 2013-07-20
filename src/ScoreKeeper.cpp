/*
 * ScoreKeeper.cpp
 *
 *  Created on: 2013-7-20
 *      Author: gangz
 */

#include "ScoreKeeper.h"

ScoreKeeper::ScoreKeeper():_score(0){
	// TODO Auto-generated constructor stub

}

ScoreKeeper::~ScoreKeeper() {
	// TODO Auto-generated destructor stub
}

void ScoreKeeper::eleminateRows(int rows){
	_score+=rows*10;
}
int ScoreKeeper::score(){
	return _score;
}

