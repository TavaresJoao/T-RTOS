#ifndef _OS_H_
#define _OS_H_

#include "os_types.h"
#include "port.h"

#define MAX_TASK 10

typedef void (*task_t)(void);

/* estrutura do tcb */
struct tcb_t_
{
  cpu_t *stk;
};
typedef struct tcb_t_ tcb_t;

/* tcb */
extern volatile tcb_t tcb[MAX_TASK];

/* installed tasks */
extern unsigned int it;

/* current task */
extern unsigned int ct;

void InstallTask(task_t task, cpu_t *stk, unsigned int stk_size);

#endif
