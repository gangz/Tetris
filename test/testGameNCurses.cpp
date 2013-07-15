#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include <ncurses.h>

#include "NcursesGraphcisDriver.h"
#include "GraphcisController.h"
#include "Game.h"
#include "MockInputListener.h"
#define PAUSE() (void)0
//#define PAUSE() getch()

TEST_GROUP(GameNCurses){
	Game* game;
	IGraphcisController* graphController;
	IGraphcisDriver* graphDriver;
	void setup(){
		graphDriver = new NcursesGraphcisDriver();
		graphController = new GraphcisController(graphDriver);
		game = new Game(graphController);
	}
	void teardown(){
		mock().clear();
		delete game;
		delete graphController;
		delete graphDriver;
	}
};


TEST(GameNCurses, init_game_gui){
	game->init();
};

TEST(GameNCurses, start_game_will_produce_a_block){
	game->init();
	game->start();
};

TEST(GameNCurses, key_down_will_move_block_down){
	game->init();
	game->start();
	PAUSE();
	game->keyDown();
	PAUSE();
	game->keyLeft();
	PAUSE();
	game->keyRight();
	PAUSE();
};

TEST_GROUP(GameNCurses_MockInput){
	Game* game;
	IGraphcisController* graphController;
	IGraphcisDriver* graphDriver;
	InputListener* input;

	void setup(){
		graphDriver = new NcursesGraphcisDriver();
		graphController = new GraphcisController(graphDriver);
		input = new MockInputListener();
		game = new Game(graphController,input);
	}
	void teardown(){
		mock().clear();
		delete game;
		delete graphController;
		delete graphDriver;
		delete input;
	}
};

#undef PAUSE
#define PAUSE() getch()
TEST(GameNCurses_MockInput, key_down_will_move_block_down_gui){
	mock().expectNCalls(10,"InputListener::getInput")
			.onObject(input)
			.ignoreOtherParameters()
			.andReturnValue((int)InputListener::MOVE_DOWN);
	mock().expectOneCall("InputListener::getInput")
			.onObject(input)
			.ignoreOtherParameters()
			.andReturnValue((int)InputListener::EXIST);

	mock().ignoreOtherCalls();
	game->init();
	game->start();
	PAUSE();
};
