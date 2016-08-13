#include <stdio.h>

#define MAX 10

int a;
int rand_seed=10;

int rand()
{
  rand_seed = rand_seed * 1103515245 +12345;
  return (unsigned int)(rand_seed / 65536) % 32768;
}

int main()
{
  int i,t,x,y;

  for (i=0; i < MAX; i++)
  {
    a=rand();
    printf("%d\n", a);
  }

  for (x=0; x < MAX-1; x++)
    for (y=0; y < MAX-x-1; y++)
      if (a > a[y+1])
      {
        t = a;
        a = a[y+1];
        a[y+1] = t;
      }

  printf("-------------------\n");
  for (i=0; i < MAX; i++)
  printf("%d\n", a);

  return 0;
}
