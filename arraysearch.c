#include <stdio.h>

main(){
  int a[] = {9, 8, 7, 6, 7};
  int i;

  for(i = 0; i < 5; i++){
    if(a[i] == 7)
      printf("7があったよ\n");
  }
}
