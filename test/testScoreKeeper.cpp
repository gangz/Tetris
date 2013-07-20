#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "ScoreKeeper.h"
TEST_GROUP(ScoreKeeperTest){

};

TEST(ScoreKeeperTest,eliminate_one_row_get_ten){
	ScoreKeeper scoreKeeper;
	scoreKeeper.eleminateRows(1);
	CHECK_EQUAL(10, scoreKeeper.score());
}
