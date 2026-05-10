#include "charcat_lib.h"

void str_concat(char *dst, const char *src)
{
  int i = 0, j = 0;
  while (dst[i] != '\0')
    i++;
  while (src[j] != '\0') {
    dst[i] = src[j];
    i++;
    j++;
  }
  dst[i] = '\0';
}
