#ifndef SCOREKEEPER_H_
#define SCOREKEEPER_H_

class ScoreKeeper {
public:
	ScoreKeeper();
	virtual ~ScoreKeeper();
	void eleminateRows(int rows);
	int score();
private:
	int _score;
};

#endif /* SCOREKEEPER_H_ */
