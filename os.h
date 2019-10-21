#ifndef _OS_H_
#define _OS_H_

#include "port.h"

typedef void (*task_t)(void);

typedef struck tcb_t_{
  cpu_t *stk;
}tcb_t;

void InstallTask(task_t task, cpu_t *stk, unsigned int stk_size);

#endif
