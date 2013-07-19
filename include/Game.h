#ifndef GAME_H_
#define GAME_H_

class IGraphcisController;
class InputListener;
class ShapePlacement;
class ICollisionDetector;
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
private:
	IGraphcisController* graphcisController;
	InputListener* inputListener;
	ShapePlacement* activeShapePlacement;
	ICollisionDetector* collisionDetector;
	ShapePlacement* borderShapePlacement;
	void reDraw();
	void listenInputEvents();
	void createShape();
};

#endif /* GAME_H_ */
