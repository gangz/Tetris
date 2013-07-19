#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include <ncurses.h>

#include "NcursesGraphcisDriver.h"
#include "GraphcisController.h"
#include "Game.h"
#include "MockInputListener.h"
#include "NullInputListener.h"
#include "NullCollisionDetector.h"
#define PAUSE() (void)0
//#define PAUSE() getch()

TEST_GROUP(GameNCurses){
	GameController* game;
	IGraphcisController* graphController;
	IGraphcisDriver* graphDriver;
	InputListener* input;
	ICollisionDetector* collisiondetector;
	void setup(){
		graphDriver = new NcursesGraphcisDriver();
		graphController = new GraphcisController(graphDriver);
		collisiondetector = new NullCollisionDector();
		input = new NullInputListener();
		game = new GameController(graphController, input, collisiondetector);
	}
	void teardown(){
		mock().clear();
		delete game;
		delete graphController;
		delete graphDriver;
		delete collisiondetector;
		delete input;
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
	GameController* game;
	IGraphcisController* graphController;
	IGraphcisDriver* graphDriver;
	InputListener* input;
	ICollisionDetector* collisiondetector;

	void setup(){
		graphDriver = new NcursesGraphcisDriver();
		graphController = new GraphcisController(graphDriver);
		input = new MockInputListener();
		collisiondetector = new NullCollisionDector();

		game = new GameController(graphController,input,collisiondetector);
	}
	void teardown(){
		mock().clear();
		delete game;
		delete graphController;
		delete graphDriver;
		delete collisiondetector;
		delete input;
	}
};

//#undef PAUSE
//#define PAUSE() getch()
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


#include "KeyboardInputListener.h"
TEST_GROUP(GameNCurses_With_Input){
	GameController* game;
	IGraphcisController* graphController;
	IGraphcisDriver* graphDriver;
	ICollisionDetector* collisionDetector;
	InputListener* input;

	void setup(){
		graphDriver = new NcursesGraphcisDriver();
		graphController = new GraphcisController(graphDriver);
		input = new KeyboardInputListener();
		collisionDetector  = new NullCollisionDector();
		game = new GameController(graphController,input, collisionDetector);
	}
	void teardown(){
		mock().clear();
		delete game;
		delete graphController;
		delete graphDriver;
		delete input;
		delete collisionDetector;
	}
};

//#undef PAUSE
//#define PAUSE() getch()
TEST(GameNCurses_With_Input, key_down_will_move_block_down_gui){
	game->init();
	game->start();
};
