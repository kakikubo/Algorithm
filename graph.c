#include <stdio.h>

main()
{
  int a[] = {4, 5, 2, 3};
  int i, j;

  for(j = 0; j < 4; j++){
    printf("a[%d]=%d|", j, a[j]);
    for(i = 1; i <= a[j]; i++){
      printf("*");
    }
    printf("\n");
  }
}
