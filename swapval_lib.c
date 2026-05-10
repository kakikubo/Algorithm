#include "swapval_lib.h"

void swapbyval(int x, int y)
{
  int temp;
  temp = x;
  x = y;
  y = temp;
}

void swapbyref(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
