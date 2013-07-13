#ifndef GAME_H_
#define GAME_H_

class IGraphcisController;
class Shape;
class Game {
public:
	Game(IGraphcisController* graphcisController);
	virtual ~Game();
	void init();
	void start();
private:
	IGraphcisController* graphcisController;
	Shape* activeShape;
};

#endif /* GAME_H_ */
