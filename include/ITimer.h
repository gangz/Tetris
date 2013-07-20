/*
 * ITimer.h
 *
 *  Created on: 2013-7-20
 *      Author: gangz
 */

#ifndef ITIMER_H_
#define ITIMER_H_

#include "ITimerEventListener.h"

class ITimer {
public:
	virtual ~ITimer(){};
    virtual void registerEventListener(ITimerEventListener *listener)=0;
    virtual void start()=0;
};


#endif /* ITIMER_H_ */
