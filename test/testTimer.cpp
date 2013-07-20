#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "MockTimerEventListener.h"
#include "LinuxTimer.h"
TEST_GROUP(TimerTest){
	ITimer* timer;
	void setup(){
		timer = new LinuxTimer();
	}
	void teardown(){
		mock().clear();
		delete timer;
	}		
};


TEST(TimerTest, start_a_timer_should_received_notification){
	ITimerEventListener *listener = new MockTimerEventListener();
	mock().expectOneCall("ITimerEventListener::timeOut")
		  .onObject(listener);
	timer->registerEventListener(listener);
	timer->start();
	mock().checkExpectations();
	delete listener;
};
