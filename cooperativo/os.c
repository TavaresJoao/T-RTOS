#include "os.h"

void InstallTask(task_t task, cpu_t *stk, unsigned int stk_size){
  stk = stk + (cpu_t)stk_size - sizeof(cpu_t);

  stk = PrepareTask(task, stk);
}
