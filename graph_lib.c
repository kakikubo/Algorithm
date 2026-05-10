#include <stdio.h>
#include "graph_lib.h"

void format_bar(char *out, int idx, int value)
{
  int i, k;
  k = sprintf(out, "a[%d]=%d|", idx, value);
  for (i = 0; i < value; i++)
    out[k + i] = '*';
  out[k + value] = '\0';
}
