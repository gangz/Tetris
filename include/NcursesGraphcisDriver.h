#ifndef NCURSESGRAPHCISDRIVER_H_
#define NCURSESGRAPHCISDRIVER_H_

#include "IGraphcisDriver.h"

class NcursesGraphcisDriver: public IGraphcisDriver {
public:
	NcursesGraphcisDriver();
	virtual ~NcursesGraphcisDriver();
	virtual void drawBox(Point left_top, Point right_bottom);
	virtual void writeText(Point pos, std::string text);
	virtual void drawCell(Point pos);
};

#endif /* NCURSESGRAPHCISDRIVER_H_ */
