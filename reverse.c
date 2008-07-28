#include <stdio.h>
#include <string.h>

main()
{
  int i, n;
  char a[] = "DOG";
  char b[10];

  n = strlen(a);
  for(i = n-1; i >= 0; i--)
    b[n-1-i] = a[i];
  b[n] = '\0';
  printf("%sは\n逆さから読むと\n%s\n", a, b);
}
