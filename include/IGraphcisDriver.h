#ifndef IGRAPHCIS_DRIVER_H_
#define IGRAPHCIS_DRIVER_H_

#include <string>

class Point{
public:
	Point(int x, int y):x(x),y(y){};
	int x;
	int y;
};
class IGraphcisDriver{
public:
	virtual ~IGraphcisDriver(){};
	virtual void drawBox(Point left_top, Point right_bottom)=0;
	virtual void writeText(Point pos, std::string text)=0;
	virtual void drawCell(Point pos)=0;
};
#endif /* IGRAPHCIS_DRIVER_H_ */
