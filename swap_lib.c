#include "swap_lib.h"

void swap_int(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int sum_range(int min, int max)
{
  int i, n;
  if (min > max)
    swap_int(&min, &max);
  n = 0;
  for (i = min; i <= max; i++)
    n += i;
  return n;
}
