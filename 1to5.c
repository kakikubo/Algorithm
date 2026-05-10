#include <stdio.h>
#include "sum1ton_lib.h"

main(){

  int i, n = 0;

  for(i = 1; i <= 5; i++){
    n = sum_1_to_n(i);
    printf("%d\n", n);
  }


  printf("%d\n", n);

}
