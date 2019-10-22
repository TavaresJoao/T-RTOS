#ifndef _PORT_H_
#define _PORT_H_

/*
  - Despachar uma tarefa

  - asm("LDHX stk_tmp") carrega o conteúdo da variável stk_tmp para o
  registrador de indexes (H:X)
  - asm("TXS") transfer index register to stack pointer: carrega SP com o
  conteúdo do registrador (H:X) - 1
  - asm("PULH") pull H from stack: desempilha e carrega o conteúdo no
  registrador H
  - asm("RTI") return from interrupt: pull (CCR), pull (A), pull (X),
  pull (PCH), pull (PCL)
*/
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
