#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        printf("height: ");
        h = GetInt();
    } while (h < 0 || h > 23);
    for (int x = 0; x < h; x++)
    {
        for (int y = h - x - 1; y > 0; y--)
        {
            printf(" ");
        }
        for (int y = x + 2; y > 0; y--)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
