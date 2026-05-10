#include <stdio.h>
#include "charcat_lib.h"

main(){

  char a[12] = "book", b[] = "marks";

  printf("%s+%s=", a, b);
  str_concat(a, b);
  printf("%s\n", a);
}

