#include "CppUTest/TestHarness.h"
#include "Shape.h"
#include "ShapePlacement.h"
#include "ShapeFactory.h"
TEST_GROUP(ShapePlacement){
	ShapeFactory shapeFactory;
	Shape* bar;
	ShapePlacement* shapePlacement;
	void setup(){
		//setup
		bar = shapeFactory.make(ShapeFactory::TYPE_BAR);
		shapePlacement = new ShapePlacement(0,0);
		shapePlacement->put(bar);
	}
	void teardown(){
		delete shapePlacement;
	}
};

TEST(ShapePlacement, place_vertical_should_add_one_if_move_down){
	//action
	shapePlacement->moveDown();
	//check
	CHECK_EQUAL(4,shapePlacement->shapeSize());
	for(int i=0;i<4;i++){
		Cell c = shapePlacement->getAt(i);
		CHECK_EQUAL(1,c.x);
		CHECK_EQUAL(i,c.y);
	}
}

TEST(ShapePlacement, place_horinzal_should_add_one_if_move_right){
	//action
	shapePlacement->moveRight();

	//check
	CHECK_EQUAL(4,shapePlacement->shapeSize());
	for(int i=0;i<4;i++){
		Cell c = shapePlacement->getAt(i);
		CHECK_EQUAL(0,c.x);
		CHECK_EQUAL(i+1,c.y);
	}
	//tear down
}

TEST(ShapePlacement, place_horinzal_should_sub_one_if_move_left){
	//action
	shapePlacement->moveLeft();

	//check
	CHECK_EQUAL(4,shapePlacement->shapeSize());
	for(int i=0;i<4;i++){
		Cell c = shapePlacement->getAt(i);
		CHECK_EQUAL(0,c.x);
		CHECK_EQUAL(i-1,c.y);
	}
	//tear down
}


