#ifndef IGRAPHCIS_DRIVER_H_
#define IGRAPHCIS_DRIVER_H_

#include <string>

struct Point{
	int x;
	int y;
};
class IGraphcisDriver{
public:
	virtual ~IGraphcisDriver(){};
	virtual void drawBox(Point left_top, Point right_bottom)=0;
	virtual void drawLine(Point start, Point end)=0;
	virtual void writeText(Point pos, std::string text)=0;
};
#endif /* IGRAPHCIS_DRIVER_H_ */
