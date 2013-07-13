#ifndef IGRAPHCIS_DRIVER_H_
#define IGRAPHCIS_DRIVER_H_

#include <string>
class IGraphcisDriver{
public:
	virtual ~IGraphcisDriver(){};
	virtual void drawBox()=0;
	virtual void drawLine()=0;
	virtual void writeText(std::string text)=0;
};
#endif /* IGRAPHCIS_DRIVER_H_ */
