#include "function_lib.h"

int calc(int a, int b)
{
  int i, n = 0;
  for (i = a; i <= b; i++)
    n += i;
  return n;
}
