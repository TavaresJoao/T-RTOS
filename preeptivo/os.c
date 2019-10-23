#include "os.h"

volatile tcb_t tcb[MAX_TASK];
unsigned int it = 0;
unsigned int ct = 0;

/*
Só está escrevendo uma tarefa, agora tenho que escrever no final
do tcb
void InstallTask(task_t task, cpu_t *stk, unsigned int stk_size){
  stk = stk + (cpu_t)stk_size - sizeof(cpu_t);

  stk = PrepareTask(task, stk);

  stk_tmp = stk;
}*/

/*
Só está escrevendo uma tarefa, agora tenho que escrever no final
do tcb
void InstallTask(task_t task, cpu_t *stk, unsigned int stk_size){
  stk = stk + (cpu_t)stk_size - sizeof(cpu_t);

  stk = PrepareTask(task, stk);

  stk_tmp = stk;

  tcb[it++] = PrepareTask
}*/

void InstallTask(task_t task, cpu_t *stk, unsigned int stk_size, cpu_t prio)
{
  stk = stk + (cpu_t)stk_size - sizeof(cpu_t);

  stk = PrepareTask(task, stk);

  tcb[it].stk = stk;
  tcb[it].ready = 1;
  tcb[it].timeout = 0;
  tcb[it].prio = prio;
  it++;
}

cpu_t *scheduler(void)
{
  cpu_t i, i_h;

  i = 1;
  i_h = 0;
  while(i < it)
  {
    if(tcb[i].prio > tcb[i_h].prio && tcb[i].ready)
    {
    	i_h = i;
    }

    i++;
  }

  ct = i_h;
  return tcb[i_h].stk;
}

void delay(long long time)
{
  tcb[ct].ready = 0;
  tcb[ct].timeout = time + OS_time;
  yield();
}
