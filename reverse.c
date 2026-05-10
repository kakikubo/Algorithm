#include <stdio.h>
#include "reverse_lib.h"

main()
{
  char a[] = "DOG";
  char b[10];

  reverse_str(b, a);
  printf("%sは\n逆さから読むと\n%s\n", a, b);
}
