/*
 * semphore.h
 *
 *  Created on: 2013-7-20
 *      Author: gangz
 */

#ifndef SEMPHORE_H_
#define SEMPHORE_H_

#include <unistd.h>
#include <sys/sem.h>

union semun {
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};

int init_sem(int sem_id, int init_value);
int del_sem(int sem_id);
int sem_p(int sem_id);
int sem_v(int sem_id);

#endif /* SEMPHORE_H_ */
