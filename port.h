#ifndef _PORT_H_
#define _PORT_H_

#define dispatcher()\
  asm("LDHX stk_tmp");\
  asm("TXS");\
  asm("PULH");\
  asm("RTI")

#define yield() asm("SWI")

#define SAVE_SP()\
  asm("TSX");\
  asm("STHX stk_tmp")

#define RESTORE_SP()\
  asm("LDHX stk_tmp");\
  asm("TXS")

typedef unsigned char cpu_t;

extern cpu_t *stk_tmp;

cpu_t *PrepareTask(void* task, cpu_t* stk);

#endif
