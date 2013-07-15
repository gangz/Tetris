#ifndef GAME_H_
#define GAME_H_

class IGraphcisController;
class InputListener;
class ShapePlacement;
class Game {
public:
	Game(IGraphcisController* graphcisController=0,
		 InputListener* inputController=0);
	virtual ~Game();
	void init();
	void start();
	void keyDown();
	void keyLeft();
	void keyRight();
private:
	IGraphcisController* graphcisController;
	InputListener* inputListener;
	ShapePlacement* activeShapePlacement;

	void reDraw();
	void listenInputEvents();
	void createShape();
};

#endif /* GAME_H_ */
