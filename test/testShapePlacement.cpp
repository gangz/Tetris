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

TEST_GROUP(ShapePlacement_Join){
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

TEST(ShapePlacement_Join,join_two_shape){
	Shape* anotherBar = shapeFactory.make(ShapeFactory::TYPE_BAR);
	ShapePlacement* anotherShapePlacement = new ShapePlacement(0,4);
	anotherShapePlacement->put(anotherBar);
	shapePlacement->join(*anotherShapePlacement);
	CHECK_EQUAL(8,shapePlacement->shapeSize());
	CHECK_EQUAL(4,shapePlacement->getAt(4).y);
	delete anotherShapePlacement;
}

TEST_GROUP(ShapePlacement_Rotation){
	ShapeFactory shapeFactory;
	ShapePlacement* shapePlacement;
	void setup(){
		//setup
		shapePlacement = new ShapePlacement(0,0);
	}
	void teardown(){
		delete shapePlacement;
	}
};

TEST(ShapePlacement_Rotation,turn_a_bar_from_h_to_v){
	Shape* bar_h = shapeFactory.make(ShapeFactory::TYPE_BAR);
	shapePlacement->put(bar_h);
	shapePlacement->turn();
	CHECK_EQUAL(0,shapePlacement->getAt(0).x);
	CHECK_EQUAL(2,shapePlacement->getAt(0).y);
	CHECK_EQUAL(1,shapePlacement->getAt(0).x);
	CHECK_EQUAL(2,shapePlacement->getAt(0).y);
	CHECK_EQUAL(2,shapePlacement->getAt(0).x);
	CHECK_EQUAL(2,shapePlacement->getAt(0).y);
	CHECK_EQUAL(3,shapePlacement->getAt(0).x);
	CHECK_EQUAL(2,shapePlacement->getAt(0).y);
}

