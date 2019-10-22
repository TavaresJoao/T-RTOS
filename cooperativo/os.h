#ifndef _OS_H_
#define _OS_H_

#include "port.h"

#define MAX_TASK 10

typedef void (*task_t)(void);

typedef struck tcb_t_{
  cpu_t *stk;
}tcb_t;

extern tcb_t tcb[MAX_TASK];
extern unsigned int it;
extern unsigend int ct;

void InstallTask(task_t task, cpu_t *stk, unsigned int stk_size);

#endif
