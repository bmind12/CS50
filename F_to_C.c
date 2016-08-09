#include <stdio.h>

int main(void)
{
  float a;
  a = 0;
  printf("\nEnter Fahrengate degree to convert: ");
  scanf("%f", &a);
  printf("Here is a converson:\n");
  printf("%6.2f degrees F = %6.2f degrees C\n", a, (a - 32) * 5 / 9);
  return 0;
}
