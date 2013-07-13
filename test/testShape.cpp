#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "ShapeFactory.h"

TEST_GROUP(Shape){

};

TEST(Shape, can_produce_a_bar){
	ShapeFactory factory;
	Shape* shape = factory.make(ShapeFactory::TYPE_BAR);
	CHECK_EQUAL(4,shape->size());
	for(int i=0;i<4;i++){
		Cell c = shape->getAt(i);
		CHECK_EQUAL(0,c.x);
		CHECK_EQUAL(i,c.y);
	}
	delete shape;
}



