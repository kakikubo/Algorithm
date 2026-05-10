#include <stdio.h>
#include "arraysearch_lib.h"

main(){
  int a[] = {9, 8, 7, 6, 7};
  int i, n;

  n = count_occurrences(a, 5, 7);
  for(i = 0; i < n; i++)
    printf("7があったよ\n");
}
