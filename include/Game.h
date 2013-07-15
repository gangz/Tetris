#ifndef GAME_H_
#define GAME_H_

class IGraphcisController;
class ShapePlacement;
class Game {
public:
	Game(IGraphcisController* graphcisController);
	virtual ~Game();
	void init();
	void start();
	void keyDown();
	void keyLeft();
	void keyRight();
private:
	IGraphcisController* graphcisController;
	ShapePlacement* activeShapePlacement;

	void reDraw();
};

#endif /* GAME_H_ */
