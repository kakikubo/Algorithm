#include <stdio.h>
#include "average_lib.h"

main(){
  int a[] = {70, 80, 60, 90};

  printf("平均は%dです。\n", average_int(a, 4));
}
