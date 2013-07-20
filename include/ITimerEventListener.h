#ifndef ITIMEREVENTLISTENER_H_
#define ITIMEREVENTLISTENER_H_

class ITimerEventListener{
public:
	virtual ~ITimerEventListener(){};
	virtual void timeOut()=0;
};


#endif /* ITIMEREVENTLISTENER_H_ */
