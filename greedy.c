#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int ff = -1;
    int q = 25;
    int d = 10;
    int n = 5;
    int p = 1;
    int c = 0;
    int r = 0;

    printf("O hai! ");

    do
    {
        printf("How much change is owed?\n");
        ff = (int) (round(GetFloat() * 100));
    } while (ff < 0);

    c = floor(ff / q);
    r = ff % q;
    c = c + floor(r / d);
    r = r % d;
    c = c + floor(r / n);
    r = r % n;
    c = c + floor(r / p);

    printf("%i\n", c);
    return 0;
}
