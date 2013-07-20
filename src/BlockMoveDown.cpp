#include "BlockMoveDown.h"
#include "Game.h"
BlockMoveDown::BlockMoveDown(GameController* game):game(game) {
}

BlockMoveDown::~BlockMoveDown() {
}

void BlockMoveDown::timeOut(){
	game->keyDown();
}
