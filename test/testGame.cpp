#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "IPainter.h"
#include "Game.h"
TEST_GROUP(Game){
	void setup(){
	}
	void teardown(){
		mock().clear();
	}
};

class MockPainter: public IPainter{
public:
	virtual ~MockPainter(){};
	virtual void drawMainFrame(){
		mock().actualCall("IPainter::drawMainFrame")
			  .onObject(this);
	};
	virtual void drawTetrisFrame(int width, int height){
		mock().actualCall("IPainter::drawTetrisFrame")
			  .onObject(this)
			  .withParameter("width",width)
			  .withParameter("height",height);
	};
	virtual void drawNextShapeArea(){
		mock().actualCall("IPainter::drawNextShapeArea")
		  .onObject(this);
	};
	virtual void writeScore(int score){
		mock().actualCall("IPainter::writeScore")
			  .onObject(this)
			  .withParameter("score",score);

	};
	virtual void writeSpeed(int speed){
		mock().actualCall("IPainter::writeSpeed")
			  .onObject(this)
			  .withParameter("speed",speed);
	};

};
TEST(Game, init_game_gui){
	IPainter* draw = new MockPainter();
	mock().expectOneCall("IPainter::drawTetrisFrame").onObject(draw)
			.withParameter("height",20)
			.withParameter("width",8);
	mock().expectOneCall("IPainter::drawNextShapeArea")
			.onObject(draw);
	mock().expectOneCall("IPainter::writeScore")
			.onObject(draw)
			.withParameter("score",0);
	mock().expectOneCall("IPainter::writeSpeed")
			.onObject(draw)
			.withParameter("speed",0);
	Game g(draw);
	g.init();
	mock().checkExpectations();
	delete draw;
};
