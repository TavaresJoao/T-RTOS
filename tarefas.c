#include "tarefas.h"

void task1(void){
  int i = 1;

  while(i<10){
    i++;
  }

  yield();
}

void task2(void){
  int j = 1;

  while(j<10){
    j++;
  }

  yield();
}
