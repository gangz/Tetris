#ifndef GAME_H_
#define GAME_H_

class IGraphcisController;
class Game {
public:
	Game(IGraphcisController* painter);
	virtual ~Game();
	void init();
private:
	IGraphcisController* painter;
};

#endif /* GAME_H_ */
