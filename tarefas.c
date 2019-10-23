#include "os.h"

void task1(void){
  int i = 1;

  while(1){
    i++;
    
    yield();
  }
}

void task2(void){
  int j = 1;

  while(1){
    j++;
    
    yield();
  }
}
