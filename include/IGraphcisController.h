#ifndef IGRAPHCIS_CONTROLLER_H_
#define IGRAPHCIS_CONTROLLER_H_
class ShapePlacement;
class IGraphcisController{
public:
	virtual ~IGraphcisController(){};
	virtual void initGUI(int area_width, int area_height)=0;
	virtual void writeScore(int score)=0;
	virtual void writeSpeed(int speed)=0;
	virtual void drawShape(const ShapePlacement* const shape)=0;
};
#endif /* IGRAPHCIS_CONTROLLER_H_ */
