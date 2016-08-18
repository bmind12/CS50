#include <stdio.h>

int main(void)
{
  int i, j, result;
  i = 996;
  j = 4;

  result = i + j - i % j;

  printf("%d\n", result);

  return 0;
}
