#ifndef GAME_H_
#define GAME_H_
#include "ScoreKeeper.h"
class BlockMoveDown;
class IGraphcisController;
class InputListener;
class ShapePlacement;
class Shape;
class ICollisionDetector;
class ITimer;
class GameController {
public:
	GameController(IGraphcisController* graphcisController,
		 InputListener* inputController,
		 ICollisionDetector* collisionDetector);
	virtual ~GameController();
	void init();
	void start();
	void keyDown();
	void keyLeft();
	void keyRight();
	void turn();
private:
	IGraphcisController* graphcisController;
	InputListener* inputListener;
	ShapePlacement* activeShapePlacement;

	ICollisionDetector* collisionDetector;
	ShapePlacement* borderShapePlacement;
	ShapePlacement* existedBlockPlacement;
	BlockMoveDown* blockMoveDown;
	ITimer* timer;
	Shape* nextShape;
	ShapePlacement* nextShapePlacement;
	void reDraw();
	void listenInputEvents();
	void createShape();
	void moveDownCollision();
	void terminate();
	void cleanGame();
	void restart();
	bool checkGameOver();
	void eleminateRows();
	void createGame();

	bool terminateFlag;
	ScoreKeeper _scoreKeeper;
};

#endif /* GAME_H_ */
