#include <stdio.h>

main(){
  int a[] = {70, 80, 60, 90};
  int i, sum = 0;

  for(i = 0; i < 4; i++)
    sum += a[i];
  printf("平均は%dです。\n", sum / 4);
}
