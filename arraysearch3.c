#include <stdio.h>

main(){
  int n = 0;
  int a[] = {9, 7, 4, 6, 4};
  int i;

  for(i = 0; i < 5; i++){
    if(a[i] == 7){
      printf("7があったよ\n");
      n = 1;
      break;
    }
  }
  if ( n == 0 )
    printf("7はなかったよ\n");

}


