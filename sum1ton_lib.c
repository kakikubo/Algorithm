#include "sum1ton_lib.h"

int sum_1_to_n(int n)
{
  int i, total = 0;
  for (i = 1; i <= n; i++)
    total += i;
  return total;
}
