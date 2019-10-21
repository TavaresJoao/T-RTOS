#include "tarefas.h"

void task1(void){
  int i = 0;

  while(1){
    i++;

    yield();
  }
}
