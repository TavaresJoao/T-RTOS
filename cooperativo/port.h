#ifndef _PORT_H_
#define _PORT_H_

//#include "os.h"

/*
  - Despachar uma tarefa

  -- asm("LDHX stk_tmp") load index register from memory: (H:X) <- (M:M + 1)
  -- asm("TXS") transfer index register to stack pointer: SP <- (H:X) - 1
  -- asm("PULH") pull H from stack: SP <- (SP + 1); pull(H)
  -- asm("RTI") return from interrupt: pull (CCR), pull (A), pull (X),
  pull (PCH), pull (PCL)
*/
#define dispatcher()\
  asm("LDHX stk_tmp");\
  asm("TXS");\
  asm("PULH");\
  asm("RTI")

/*
  - Desistir do processador

  -- asm("SWI") software interrupt
*/
#define yield() asm("SWI")

/*
  - Salvar o stack pointer

  -- asm("TSX") transfer stack pointer to index register: (H:X) <- SP + 1
  -- asm("STHX stk_tmp") store index register: (M:M + 1) <- (H:X)
*/
#define SAVE_SP()\
  asm("TSX");\
  asm("STHX stk_tmp")

/*
  - Carregar o stack pointer

  -- asm("LDHX stk_tmp") load index register from memory: (H:X) <- (M:M + 1)
  -- asm("TXS") transfer index register to stack pointer: SP <- (H:X) - 1
*/
#define RESTORE_SP()\
  	asm("LDHX stk_tmp");\
    asm("TXS")

/*
  - Preparar Tarefa

  -- é uma função que empilha os valores do PCL, PCH, X, A, CCR e (H:X)
  predefinidos
*/
cpu_t *PrepareTask(void* task, cpu_t* stk);

/*
  - software interrupt

  -- função que será executada quando houover uma SWI
*/
interrupt void SWI(void);

/*
  - Variável para trabalhar com o stack pointer

  -- é um pointeito que contem o valor do stack pointer e é usado para armezar
  o SP na memória, ou carregar dela para o SP.
*/
extern cpu_t *stk_tmp;


#endif
