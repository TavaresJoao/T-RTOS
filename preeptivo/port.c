#include "os.h"
#include "derivate.h"

cpu_t *stk_tmp;

cpu_t *PrepareTask(void* task, cpu_t* stk)
{
  *stk-- = (cpu_t)task;           // PCL
  *stk-- = (cpu_t)((int)task>>8); // PCH
  *stk-- = 0;                     // X
  *stk-- = 0;                     // A
  *stk-- = 0;                     // CCR
  *stk = 0;                       // H:X

  return stk;
}

interrupt void SWI(void)
{
  SAVE_SP();
  tcb[ct].stk = stk_tmp;

  stk_tmp = scheduler();
  RESTORE_SP();
}

void OS_init_timer(void)
{
  TPM1SC = 0;
  TPM1MOD = 19999;
  TPM1SC = 0x48;
}

// FAZER O TICK TIMER
