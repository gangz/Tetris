#ifndef MOCKGRAPHCISCONTROLLER_H_
#define MOCKGRAPHCISCONTROLLER_H_
#include "IGraphcisController.h"
class MockGraphcisController: public IGraphcisController{
public:
	virtual ~MockGraphcisController(){};
	virtual void initGUI(int area_width, int area_height){
		mock().actualCall("IGraphcisController::initGUI")
				.onObject(this)
				.withParameter("area_width",area_width)
				.withParameter("area_height",area_height);
	}

	virtual void writeScore(int score){
		mock().actualCall("IGraphcisController::writeScore")
			  .onObject(this)
			  .withParameter("score",score);

	};
	virtual void writeSpeed(int speed){
		mock().actualCall("IGraphcisController::writeSpeed")
			  .onObject(this)
			  .withParameter("speed",speed);
	};

	virtual void drawShape(const ShapePlacement* const shape){
		mock().actualCall("IGraphcisController::drawShape")
				.onObject(this)
				.withParameter("shape",(void*)shape);
	}

	virtual void cleanTetrisArea(){
		mock().actualCall("IGraphcisController::cleanTetrisArea")
					  .onObject(this);
	}
	virtual void drawGameOver(){
		mock().actualCall("IGraphcisController::drawGameOver")
					  .onObject(this);
	}

};



#endif /* MOCKGRAPHCISCONTROLLER_H_ */
