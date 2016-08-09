#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("minutes: ");
    int min = GetInt();
    int bot = min * 1.5 * 128 / 16;
    printf("bottles: %i\n", bot);
    return 0;
}