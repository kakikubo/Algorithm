#include <string.h>
#include "reverse_lib.h"

void reverse_str(char *dst, const char *src)
{
  int n = strlen(src);
  int i;
  for (i = n - 1; i >= 0; i--)
    dst[n - 1 - i] = src[i];
  dst[n] = '\0';
}
