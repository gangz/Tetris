#ifndef GAME_H_
#define GAME_H_

class IGraphcisController;
class Game {
public:
	Game(IGraphcisController* graphcisController);
	virtual ~Game();
	void init();
	void start();
private:
	IGraphcisController* graphcisController;
};

#endif /* GAME_H_ */
