#include <stdio.h>

void swap(int *, int *);
void sum(int, int);

main()
{
  sum(1, 5);
  sum(10, 5);
  sum(1, 10);
  sum(2, 2);
}

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
void sum(int min, int max)
{
  int i, n;

  if(min > max)
    swap(&min, &max);

  printf("%d", min);
  n = min;
  for(i = min+1; i <= max; i++){
    printf("+%d", i);
    n += i;
  }
  printf("=%d\n", n);
  printf("%dから%dまでの和は%d\n", min, max, n);
}



