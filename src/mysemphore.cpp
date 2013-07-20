#include "mysemaphore.h"
#include <assert.h>
int init_sem(int sem_id, int init_value) {
	union semun sem_union;
	sem_union.val = init_value;
	assert (semctl(sem_id, 0, SETVAL, sem_union) != -1);
	return 0;
}
int del_sem(int sem_id) {
	union semun sem_union;
	assert (semctl(sem_id, 0, IPC_RMID, sem_union) != -1);
	return 0;
}
int sem_p(int sem_id) {
	struct sembuf sem_buf;
	sem_buf.sem_num = 0; //信号量编号
	sem_buf.sem_op = -1; //P操作
	sem_buf.sem_flg = SEM_UNDO; //系统退出前未释放信号量，系统自动释放
	assert (semop(sem_id, &sem_buf, 1)!= -1) ;
	return 0;
}
 int sem_v(int sem_id) {
     struct sembuf sem_buf;
     sem_buf.sem_num=0;
     sem_buf.sem_op=1;//V操作
     sem_buf.sem_flg=SEM_UNDO;
     assert (semop(sem_id,&sem_buf,1)!=-1);
     return 0;
}
