#include <stdio.h>
#include "swap_lib.h"

void print_sum(int min, int max);

main()
{
  print_sum(1, 5);
  print_sum(10, 5);
  print_sum(1, 10);
  print_sum(2, 2);
}

void print_sum(int min, int max)
{
  int i, n;

  if(min > max)
    swap_int(&min, &max);

  printf("%d", min);
  n = min;
  for(i = min+1; i <= max; i++){
    printf("+%d", i);
    n += i;
  }
  printf("=%d\n", n);
  printf("%dから%dまでの和は%d\n", min, max, n);
}



