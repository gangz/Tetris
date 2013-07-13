#ifndef IPAINTER_H_
#define IPAINTER_H_
class IPainter{
public:
	virtual ~IPainter(){};
	virtual void drawMainFrame()=0;
	virtual void drawTetrisFrame(int width, int height)=0;
	virtual void drawNextShapeArea()=0;
	virtual void writeScore(int score)=0;
	virtual void writeSpeed(int speed)=0;
	//	virtual void drawBlock(int )
};
#endif /* IPAINTER_H_ */
