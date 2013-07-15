#ifndef GAME_H_
#define GAME_H_

class IGraphcisController;
class InputController;
class ShapePlacement;
class Game {
public:
	Game(IGraphcisController* graphcisController=0,
		 InputController* inputController=0);
	virtual ~Game();
	void init();
	void start();
	void keyDown();
	void keyLeft();
	void keyRight();
private:
	IGraphcisController* graphcisController;
	InputController* inputController;
	ShapePlacement* activeShapePlacement;

	void reDraw();
};

#endif /* GAME_H_ */
