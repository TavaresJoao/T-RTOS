#include "tarefas.h"

void task1(void){
  static int i = 1;

  while(1){
    i++;

    yield();
  }
}

void task2(void){
  static int j = 0;

  while(1){
    j -= 1;

    yield();
  }
}
