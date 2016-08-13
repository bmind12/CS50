#include <stdio.h>

#define MAX 10

int a;
int rand_seed=10;

int rand()
{
  rand_seed = rand_seed * 1103515245 +12345;
  return (unsigned int)(rand_seed / 65536) % 32768
}

int main()
{
  int i,t,x,y;

  for (i=0; i < MAX; i++)
  {
    a=rand()
    printf("%d\n", a);
  }

  return 0;
}
