#ifndef MOCKTIMEREVENTLISTENER_H_
#define MOCKTIMEREVENTLISTENER_H_
#include "ITimerEventListener.h"
class MockTimerEventListener: public ITimerEventListener{
public:
	virtual ~MockTimerEventListener(){};
	virtual void timeOut(){
		mock().actualCall("ITimerEventListener::timeOut")
			  .onObject(this);
	}
};



#endif /* MOCKTIMEREVENTLISTENER_H_ */
