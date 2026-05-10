#include <stdio.h>
#include "swapval_lib.h"

main()
{
  int a = 2, b = 7;
  swapbyval(a, b);
  printf("a= %d, b= %d\n", a , b);
  swapbyref(&a, &b);
  printf("a= %d, b= %d\n", a , b);
}
