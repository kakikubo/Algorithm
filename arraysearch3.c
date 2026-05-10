#include <stdio.h>
#include "arraysearch_lib.h"

main(){
  int a[] = {9, 7, 4, 6, 4};

  if ( contains(a, 5, 7) )
    printf("7があったよ\n");
  else
    printf("7はなかったよ\n");

}


