#include "CppUTest/TestHarness.h"
#include "NcursesGraphcisDriver.h"
#include "ncurses.h"
TEST_GROUP(NcursesDriver){
	NcursesGraphcisDriver* driver;
	void setup(){
		driver = new NcursesGraphcisDriver();
	}
	void teardown(){
		delete driver;
	}
};

IGNORE_TEST(NcursesDriver,draw_a_box){
	driver->drawBox(Point(1,1),Point(10,10));
	getch();
}

IGNORE_TEST(NcursesDriver,write_a_text){
	driver->writeText(Point(2,2),"hello world");
	getch();
}
