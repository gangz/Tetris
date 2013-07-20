#ifndef LINUX_TIMER_H_
#define LINUX_TIMER_H_
#include "ITimer.h"
#include <vector>
class LinuxTimer: public ITimer{
public:
	LinuxTimer();
	virtual ~LinuxTimer();
	virtual void registerEventListener(ITimerEventListener *listener);
	virtual void start();
	void timeout();
private:
	std::vector<ITimerEventListener*> listeners;
};

#endif /* LINUX_TIMER_H */
