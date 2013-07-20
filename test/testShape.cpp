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

TEST(Shape, eleminate_a_whole_row){
	ShapeFactory factory;
	Shape* shape = factory.make(ShapeFactory::TYPE_BAR);
	int rows = shape->eleminate(4);
	CHECK_EQUAL(1,rows);
	CHECK_EQUAL(0,shape->size());
	delete shape;
}

TEST(Shape, eleminate_a_row_should_be_compressed){
	Shape* shape = new Shape();
	shape->add(Cell(0,0));
	shape->add(Cell(1,0));
	shape->add(Cell(1,1));

	int rows = shape->eleminate(2);
	CHECK_EQUAL(1,rows);
	CHECK_EQUAL(1,shape->size());
	CHECK_EQUAL(1,shape->getAt(0).x);
	CHECK_EQUAL(0,shape->getAt(0).y);
	delete shape;
}



