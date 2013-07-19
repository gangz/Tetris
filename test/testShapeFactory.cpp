#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "ShapeFactory.h"

TEST_GROUP(ShapeFactory){
	ShapeFactory shapeFactory;
};

TEST(ShapeFactory, make_a_wall){

	Shape* shape = shapeFactory.makeWall(22,10);
	Cell c = shape->getAt(0);
	CHECK_EQUAL(0,c.x);
	CHECK_EQUAL(0,c.y);
	delete shape;
}