#include "arraysearch_lib.h"

int count_occurrences(const int *a, int n, int target)
{
  int i, c = 0;
  for (i = 0; i < n; i++)
    if (a[i] == target)
      c++;
  return c;
}

int contains(const int *a, int n, int target)
{
  int i;
  for (i = 0; i < n; i++)
    if (a[i] == target)
      return 1;
  return 0;
}
