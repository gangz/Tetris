#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "IGraphcisController.h"
#include "Game.h"
TEST_GROUP(Game){
	void setup(){
	}
	void teardown(){
		mock().clear();
	}
};

class MockGraphcisController: public IGraphcisController{
public:
	virtual ~MockGraphcisController(){};
	virtual void initGUI(int area_width, int area_height){
//		virtual void drawMainFrame()=0;
//		virtual void drawTetrisFrame(int width, int height)=0;
//		virtual void drawNextShapeArea()=0;
		mock().actualCall("IGraphcisController::initGUI")
				.onObject(this)
				.withParameter("area_width",area_width)
				.withParameter("area_height",area_height);
	}
	virtual void drawMainFrame(){
		mock().actualCall("IGraphcisController::drawMainFrame")
			  .onObject(this);
	};
	virtual void drawTetrisFrame(int width, int height){
		mock().actualCall("IGraphcisController::drawTetrisFrame")
			  .onObject(this)
			  .withParameter("width",width)
			  .withParameter("height",height);
	};
	virtual void drawNextShapeArea(){
		mock().actualCall("IGraphcisController::drawNextShapeArea")
		  .onObject(this);
	};
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

};
TEST(Game, init_game_gui){
	IGraphcisController* draw = new MockGraphcisController();
	mock().expectOneCall("IGraphcisController::drawTetrisFrame").onObject(draw)
			.withParameter("height",20)
			.withParameter("width",8);
	mock().expectOneCall("IGraphcisController::drawNextShapeArea")
			.onObject(draw);
	mock().expectOneCall("IGraphcisController::writeScore")
			.onObject(draw)
			.withParameter("score",0);
	mock().expectOneCall("IGraphcisController::writeSpeed")
			.onObject(draw)
			.withParameter("speed",0);
	Game g(draw);
	g.init();
	mock().checkExpectations();
	delete draw;
};
