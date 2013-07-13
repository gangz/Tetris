#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "IGraphcisController.h"
#include "MockGraphcisController.h"
#include "Game.h"
TEST_GROUP(Game){
	Game *game;
	IGraphcisController* draw;
	void setup(){
		draw = new MockGraphcisController();
		game = new Game(draw);
	}
	void teardown(){
		mock().clear();
		delete game;
		delete draw;
	}
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

TEST(Game, start_game_will_produce_first_block){
	mock().expectOneCall("IGraphcisController::drawShape")
			.onObject(draw)
			.ignoreOtherParameters();
	game->start();
	mock().checkExpectations();
};
