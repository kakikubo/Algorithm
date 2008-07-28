#include <stdio.h>

main(){

  int i = 0 , j = 0;
  char a[12] = "book", b[] = "marks";

  printf("%s+%s=", a, b);
  while(a[i] != '\0')
    i++;

  while(b[j] != '\0'){
    a[i] = b[j];
    i++;
    j++;
  }
  a[i] = '\0';
  printf("%s\n", a);
}

