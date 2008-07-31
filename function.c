#include <stdio.h>

int calc(int, int);

main()
{
  int c;
  c = calc(1, 5);
  printf("%d\n", c);
}

int calc(int a, int b)
{
  int i, n = 0;
  for(i = a; i <= b; i++)
    n += i;
  return n;
}
