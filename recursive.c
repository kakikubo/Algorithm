#include <stdio.h>

int kaijo(int);

main()
{
  printf("%d! = %d\n", 5, kaijo(5));
}

int kaijo(int n)
{
  if(n == 0)
    return 1;
  else
    return (n * kaijo(n-1));
}
