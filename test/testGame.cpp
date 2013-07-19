#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "IGraphcisController.h"
#include "MockGraphcisController.h"
#include "MockInputListener.h"
#include "NullInputListener.h"
#include "NullCollisionDetector.h"

#include "Game.h"

TEST_GROUP(Game_GUI_Control){
	GameController *game;
	IGraphcisController* draw;
	InputListener* input;
	ICollisionDetector* collisionDetector;
	void setup(){
		draw = new MockGraphcisController();
		input = new NullInputListener();
		collisionDetector = new NullCollisionDector();
		game = new GameController(draw, input, collisionDetector);
	}
	void teardown(){
		mock().clear();
		delete game;
		delete draw;
		delete collisionDetector;
		delete input;
	}
};


TEST(Game_GUI_Control, init_game_gui){

	mock().expectOneCall("IGraphcisController::initGUI")
			.onObject(draw)
			.ignoreOtherParameters();
	mock().expectOneCall("IGraphcisController::writeScore")
			.onObject(draw)
			.withParameter("score",0);
	mock().expectOneCall("IGraphcisController::writeSpeed")
			.onObject(draw)
			.withParameter("speed",0);

	game->init();
	mock().checkExpectations();
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
	GameController *game;
	IGraphcisController* draw;
	InputListener* input;
	ICollisionDetector* collisionDetector;
	void setup(){
		input = new MockInputListener();
		draw = new MockGraphcisController();
		collisionDetector = new NullCollisionDector();
		game = new GameController(draw,input,collisionDetector);
	}
	void teardown(){
		mock().clear();
		delete game;
		delete draw;
		delete input;
		delete collisionDetector;
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
