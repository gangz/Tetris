#include "LinuxTimer.h"
#include <assert.h>
#include  <stdio.h>
#include  <unistd.h>
#include  <signal.h>
#include  <string.h>
#include  <sys/time.h>
#include  <errno.h>

extern "C"{
static LinuxTimer* timer=0;
void  time_out( int number);
}

void  time_out( int number)
{
	(void)number;
	((LinuxTimer*)timer)->timeout();
	return ;
}

void LinuxTimer::timeout(){
   for(std::vector<ITimerEventListener*>::iterator iter = listeners.begin();
			iter!=listeners.end();iter++){
		(*iter)->timeOut();
	}
}
LinuxTimer::LinuxTimer(){
	timer = this;
}

LinuxTimer::~LinuxTimer(){

}

void LinuxTimer::registerEventListener(ITimerEventListener *listener)
{
	listeners.push_back(listener);
};
void LinuxTimer::start()
{
    signal(SIGALRM,  time_out);
    struct   itimerval  tick;
    tick.it_value.tv_sec  =   1 ;    // 0秒钟后将启动定时器
    tick.it_value.tv_usec  =   0 ;
    tick.it_interval.tv_sec    = 1 ;  // 定时器启动后，每隔1秒将执行相应的函数
    tick.it_interval.tv_usec  =   0 ;
    // setitimer将触发SIGALRM信号
    int   ret  =   setitimer(ITIMER_REAL,  & tick,  NULL);
    assert(ret==0); //Timer must be success
};





