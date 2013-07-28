#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "CollisionDetector.h"
#include "ShapePlacement.h"
#include "IInputListener.h"
#include "NullCollisionDetector.h"
#include "ShapeFactory.h"
TEST_GROUP(CollisionDetectorTest){
	ShapeFactory shapeFactory;
	ICollisionDetector* collisionDetector;
	void setup(){
		collisionDetector = new CollisionDetector();
	}
	void teardown(){
		delete collisionDetector;
	}
};

TEST(CollisionDetectorTest,move_down_shoudld_be_ok){
	ShapePlacement shapePlacement_1(0,0);
	shapePlacement_1.put(shapeFactory.make(Shape::TYPE_BAR));

	ShapePlacement shapePlacement_2(2,0);
	shapePlacement_2.put(shapeFactory.make(Shape::TYPE_BAR));

	CHECK_FALSE(collisionDetector->isCollision(&shapePlacement_1, &shapePlacement_2, InputListener::MOVE_DOWN));
}

TEST(CollisionDetectorTest,move_down_shoudld_be_collision){
	ShapePlacement shapePlacement_1(0,0);
	shapePlacement_1.put(shapeFactory.make(Shape::TYPE_BAR));
	shapePlacement_1.moveDown();

	ShapePlacement shapePlacement_2(2,0);
	shapePlacement_2.put(shapeFactory.make(Shape::TYPE_BAR));

	CHECK_TRUE(collisionDetector->isCollision(&shapePlacement_1, &shapePlacement_2, InputListener::MOVE_DOWN));
}

TEST(CollisionDetectorTest,move_left_shoudld_be_collision){
	ShapePlacement shapePlacement_1(0,4);
	shapePlacement_1.put(shapeFactory.make(Shape::TYPE_BAR));

	ShapePlacement shapePlacement_2(0,0);
	shapePlacement_2.put(shapeFactory.make(Shape::TYPE_BAR));

	CHECK_TRUE(collisionDetector->isCollision(&shapePlacement_1, &shapePlacement_2, InputListener::MOVE_LEFT));
}

TEST(CollisionDetectorTest,move_left_shoudld_be_ok){
	ShapePlacement shapePlacement_1(0,5);
	shapePlacement_1.put(shapeFactory.make(Shape::TYPE_BAR));

	ShapePlacement shapePlacement_2(0,0);
	shapePlacement_2.put(shapeFactory.make(Shape::TYPE_BAR));

	CHECK_FALSE(collisionDetector->isCollision(&shapePlacement_1, &shapePlacement_2, InputListener::MOVE_LEFT));
}

TEST(CollisionDetectorTest,move_right_shoudld_be_ok){
	ShapePlacement shapePlacement_1(0,0);
	shapePlacement_1.put(shapeFactory.make(Shape::TYPE_BAR));

	ShapePlacement shapePlacement_2(0,5);
	shapePlacement_2.put(shapeFactory.make(Shape::TYPE_BAR));

	CHECK_FALSE(collisionDetector->isCollision(&shapePlacement_1, &shapePlacement_2, InputListener::MOVE_RIGHT));
}

TEST(CollisionDetectorTest,move_right_shoudld_be_collision){
	ShapePlacement shapePlacement_1(0,0);
	shapePlacement_1.put(shapeFactory.make(Shape::TYPE_BAR));

	ShapePlacement shapePlacement_2(0,4);
	shapePlacement_2.put(shapeFactory.make(Shape::TYPE_BAR));

	CHECK_TRUE(collisionDetector->isCollision(&shapePlacement_1, &shapePlacement_2, InputListener::MOVE_RIGHT));
}
