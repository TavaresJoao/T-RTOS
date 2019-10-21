#include "os.h"

tcb_t tcb[10];
unsigened int it = 0;//installed tasks
unsigend int ct = 0;// current task

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
