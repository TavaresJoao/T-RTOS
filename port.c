#include "port.h"

cpu_t *stk_tmp;

cpu_t *PrepareTask(void* task, cpu_t* stk){
  *stk-- = (cpu_t)task;
  *stk-- = (cpu_t)((int)task>>8);
  *stk-- = 0;
  *stk-- = 0;
  *stk-- = 0;
  *stk = 0;

  return stk;
}

interrupt void SWI(void){
  SAVE_SP();
  tcb[ct++].stk = stk_tmp;
  if(ct > it)
    ct = 0;

  stk_tmp = tcb[ct].stk;
  RESTORE_SP();
}
