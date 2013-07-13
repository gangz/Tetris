#include "CppUTest/TestHarness.h"
#include "Shape.h"
#include "ShapePlacement.h"
#include "ShapeFactory.h"
TEST_GROUP(ShapePlacement){

};

TEST(ShapePlacement, place_should_add_one_if_move_down){
	//setup
	ShapeFactory shapeFactory;
	Shape* bar = shapeFactory.make(ShapeFactory::TYPE_BAR);
	ShapePlacement shapePlacement(0,0);
	shapePlacement.put(bar);

	//action
	shapePlacement.moveDown();

	//check
	CHECK_EQUAL(4,shapePlacement.shapeSize());
	for(int i=0;i<4;i++){
		Cell c = shapePlacement.getAt(i);
		CHECK_EQUAL(1,c.x);
		CHECK_EQUAL(i,c.y);
	}
	//tear down
	delete bar;

}
