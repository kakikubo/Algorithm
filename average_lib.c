#include "average_lib.h"

int average_int(const int *a, int n)
{
  int i, sum = 0;
  for (i = 0; i < n; i++)
    sum += a[i];
  return sum / n;
}
