#include <stdio.h>
void swapbyval(int , int );
void swapbyref(int *, int *);

int temp;
main()
{
  int a = 2, b = 7;
  swapbyval(a, b);
  printf("a= %d, b= %d\n", a , b);
  swapbyref(&a, &b);
  printf("a= %d, b= %d\n", a , b);
}

void swapbyval(int x, int y)
{
  temp = x;
  x = y;
  y = temp;

}

void swapbyref(int *x, int *y)
{
  temp = *x;
  *x = *y;
  *y = temp;
}
