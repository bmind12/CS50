#include <stdio.h>

int main(void) {

  float s, n;
  char o;

  do {

    scanf("%f %c", &n, &o);

    switch (o) {
      case '+':
        s = s + n;
        break;
      case '-':
        s = s - n;
        break;
      case '*':
        s = s * n;
        break;
      case '/':
        if (n == 0) {
          printf("Division by 0 is not possible\n");
          break;
        }
        s = s / n;
        break;
      case 'S':
        s = n;
        break;
      default:
        printf("Operator is unknown\n");
    }

    s > 0 ? printf("= %.2f\n", s) : printf("%2.f\n", s);

  } while (o != 'E');

    printf("End of calculations\n");

  return 0;
}
