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

};
TEST(Game, init_game_gui){
	IGraphcisController* draw = new MockGraphcisController();
	mock().expectOneCall("IGraphcisController::initGUI")
			.onObject(draw)
			.ignoreOtherParameters();
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
