#include "LinuxTimer.h"

LinuxTimer::LinuxTimer(){

}

LinuxTimer::~LinuxTimer(){

}

void LinuxTimer::registerEventListener(ITimerEventListener *listener)
{
	listeners.push_back(listener);
};
void LinuxTimer::start()
{
	for(std::vector<ITimerEventListener*>::iterator iter = listeners.begin();
			iter!=listeners.end();iter++){
		(*iter)->timeOut();
	}
};


