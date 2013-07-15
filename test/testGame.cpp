#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "IGraphcisController.h"
#include "MockGraphcisController.h"
#include "MockInputListener.h"
#include "Game.h"

TEST_GROUP(Game_GUI_Control){
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


TEST(Game_GUI_Control, init_game_gui){
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

TEST(Game_GUI_Control, start_game_will_produce_first_block){
	mock().expectOneCall("IGraphcisController::drawShape")
			.onObject(draw)
			.ignoreOtherParameters();
	mock().ignoreOtherCalls();

	game->start();
	mock().checkExpectations();
};

TEST_GROUP(Game_Input){
	Game *game;
	IGraphcisController* draw;
	InputListener* input;
	void setup(){
		input = new MockInputListener();
		draw = new MockGraphcisController();
		game = new Game(draw,input);
	}
	void teardown(){
		mock().clear();
		delete game;
		delete draw;
		delete input;
	}
};
TEST(Game_Input,start_game_will_listen_input){
	mock().expectOneCall("InputListener::getInput")
			.onObject(input)
			.ignoreOtherParameters()
			.andReturnValue((int)InputListener::EXIST);
	mock().ignoreOtherCalls();

	game->start();
	mock().checkExpectations();
}

TEST(Game_Input,start_game_will_listen_input_until_exist){
	mock().expectOneCall("InputListener::getInput")
			.onObject(input)
			.ignoreOtherParameters()
			.andReturnValue((int)InputListener::MOVE_DOWN);
	mock().expectOneCall("InputListener::getInput")
			.onObject(input)
			.ignoreOtherParameters()
			.andReturnValue((int)InputListener::EXIST);

	mock().ignoreOtherCalls();

	game->start();
	mock().checkExpectations();
}
