#include "port.h"

cpu_t *PrepareTask(void* task, cpu_t* stk){
  *stk-- = (cpu_t)(task);
  *stk-- = (cpu_t)(task>>8);
  *stk-- = 0;
  *stk-- = 0;
  *stk-- = 0;

  return stk;
}
