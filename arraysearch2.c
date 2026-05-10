#include <stdio.h>
#include "arraysearch_lib.h"

main(){
  int a[] = {9, 8, 4, 6, 4};
  int i, n;

  n = count_occurrences(a, 5, 7);
  for(i = 0; i < n; i++)
    printf("7があったよ\n");
  if ( n == 0 )
    printf("7はなかったよ\n");
  else
    printf("7は%d個あったよ\n", n);

}


