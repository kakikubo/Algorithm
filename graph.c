#include <stdio.h>
#include "graph_lib.h"

main()
{
  int a[] = {4, 5, 2, 3};
  int j;
  char buf[64];

  for(j = 0; j < 4; j++){
    format_bar(buf, j, a[j]);
    printf("%s\n", buf);
  }
}
