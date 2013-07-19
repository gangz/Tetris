#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "ICollisionDetector.h"
#include "ShapePlacement.h"
#include "IInputListener.h"
#include "NullCollisionDetector.h"
#include "ShapeFactory.h"
TEST_GROUP(CollisionDetectorTest){
	ShapeFactory shapeFactory;
};

TEST(CollisionDetectorTest,move_down_shoudld_be_ok){
	ICollisionDetector* collisionDetector = new NullCollisionDector();
	ShapePlacement shapePlacement_1(0,0);
	shapePlacement_1.put(shapeFactory.make(ShapeFactory::TYPE_BAR));

	ShapePlacement shapePlacement_2(2,0);
	shapePlacement_2.put(shapeFactory.make(ShapeFactory::TYPE_BAR));

	CHECK_FALSE(collisionDetector->isCollision(&shapePlacement_1, &shapePlacement_2, InputListener::MOVE_DOWN));
	delete collisionDetector;
}
