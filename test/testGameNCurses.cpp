#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include <ncurses.h>

#include "NcursesGraphcisDriver.h"
#include "GraphcisController.h"
#include "Game.h"
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
	getch();
};
