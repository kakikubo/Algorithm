#include <stdio.h>

main(){
  int n = 0;
  int a[] = {9, 8, 4, 6, 4};
  int i;

  for(i = 0; i < 5; i++){
    if(a[i] == 7){
      printf("7があったよ\n");
      n++;
    }
  }
  if ( n == 0 )
    printf("7はなかったよ\n");
  else
    printf("7は%d個あったよ\n", n);

}


