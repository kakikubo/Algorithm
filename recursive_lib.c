#include "recursive_lib.h"

int kaijo(int n)
{
  if (n == 0)
    return 1;
  else
    return (n * kaijo(n - 1));
}
