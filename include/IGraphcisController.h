#ifndef IGRAPHCIS_CONTROLLER_H_
#define IGRAPHCIS_CONTROLLER_H_
class IGraphcisController{
public:
	virtual ~IGraphcisController(){};
	virtual void drawMainFrame()=0;
	virtual void drawTetrisFrame(int width, int height)=0;
	virtual void drawNextShapeArea()=0;
	virtual void writeScore(int score)=0;
	virtual void writeSpeed(int speed)=0;
	//	virtual void drawBlock(int )
};
#endif /* IGRAPHCIS_CONTROLLER_H_ */
