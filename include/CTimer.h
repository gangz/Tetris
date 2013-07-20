/*
 * CTimer.h
 *
 *  Created on: 2013-7-20
 *      Author: gangz
 */

#ifndef CTIMER_H_
#define CTIMER_H_

#include <pthread.h>
#include <sys/time.h>
class CTimer
{
public:
    CTimer();
    CTimer(long second, long microsecond);
    virtual ~CTimer();
    void SetTimer(long second,long microsecond);
    void StartTimer();
    void StopTimer();
private:
    pthread_t thread_timer;
    long m_second, m_microsecond;
    static void *OnTimer_stub(void *p)
    {
        (static_cast<CTimer*>(p))->thread_proc();
    }
    void thread_proc();
    virtual void OnTimer()=0;
};

#endif /* CTIMER_H_ */
