#ifndef GAME_H_
#define GAME_H_

class IPainter;
class Game {
public:
	Game(IPainter* painter);
	virtual ~Game();
	void init();
private:
	IPainter* painter;
};

#endif /* GAME_H_ */
